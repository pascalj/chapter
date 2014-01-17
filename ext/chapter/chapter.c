#include <ruby.h>
#include <mp4v2/mp4v2.h>
#include <stdio.h>
#include <string.h>

static VALUE
rb_get_chapters(VALUE self, VALUE path) {
    char* fileName = StringValuePtr(path);
    MP4FileHandle file = MP4Read(fileName, 0);
    if(file == MP4_INVALID_FILE_HANDLE )
    {
       rb_raise(rb_eException, "could not load file");
       return Qnil;
    }

    MP4Chapter_t * chapters = 0;
    uint32_t chapterCount = 0;

    // get the list of chapters
    MP4ChapterType chtp = MP4GetChapters(file, &chapters, &chapterCount, MP4ChapterTypeAny);

    uint32_t i;
    uint32_t pos = 0;
    VALUE result = rb_ary_new();
    for (i = 0; i < chapterCount; ++i)
    {
      VALUE chapter = rb_hash_new();
      // print the infos
      rb_hash_aset(chapter, rb_str_new2("title"), rb_str_new2(chapters[i].title));
      rb_hash_aset(chapter, rb_str_new2("duration"), INT2NUM(chapters[i].duration));
      rb_hash_aset(chapter, rb_str_new2("position"), INT2NUM(pos));
      rb_ary_push(result, chapter);
      pos = pos + chapters[i].duration;
    }
    // free up the memory
    MP4Free(chapters);
    MP4Close(file);
    return result;
}

static VALUE
rb_set_chapters(VALUE self, VALUE path, VALUE chapters) {
    char* fileName = StringValuePtr(path);
    MP4FileHandle file = MP4Modify(fileName, 0, 0);
    if(file == MP4_INVALID_FILE_HANDLE )
    {
       rb_raise(rb_eException, "could not load file");
       return Qnil;
    }
    uint32_t chapter_len = RARRAY_LEN(chapters);
    uint32_t i;
    MP4Chapter_t newChapters[chapter_len]; 
    MP4Chapter_t *chapter = malloc(sizeof(MP4Chapter_t));
    for (i = 0; i < chapter_len; i++) {

        VALUE duration = rb_hash_aref(rb_ary_entry(chapters, i), rb_str_new2("duration"));
        VALUE title = rb_hash_aref(rb_ary_entry(chapters, i), rb_str_new2("title"));

        chapter->duration = NUM2UINT(duration);
        strcpy(chapter->title, StringValuePtr(title));
        newChapters[i] = *chapter;
    }
    free(chapter);

    MP4SetChapters(file, &newChapters[0], chapter_len, MP4ChapterTypeQt);
    MP4Close(file);
    return Qnil;
}

/* ruby calls this to load the extension */
void Init_chapter(void) {
    VALUE mp4v2 = rb_define_module("MP4v2");
    VALUE klass = rb_define_class_under(mp4v2,"Chapter", rb_cObject);
    rb_define_singleton_method(klass, "chapters", rb_get_chapters, 1);
    rb_define_singleton_method(klass, "set_chapters", rb_set_chapters, 2);
}
