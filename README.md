#chapter#

chapter is a simple gem to set mp4 chapter information.

##prerequisites##
To use it, you'll need [mp4v2][1] installed on your system.

On OS X:

    brew install mp4v2
On FreeBSD:

    cd /usr/ports/multimedia/mp4v2 && make install clean
On other systems you might need to compile it yourself. Please refer to the mp4v2 [documentation][2] on how to do that.
##Installation##
Via Rubygems:

    gem install chapter
Or add the gem to your `Gemfile`:

    gem 'chapter'

##Usage##

###Get the chapters in a file###

    require 'chapter'
    chapters = Chapter.chapters '/path/to/file.m4a'
`chapters` will be an array of hashes. Each hash represents a chapter with its position and duration (both in microseconds) and its title.
####Example

    [
      {"title"=>"Introduction", "duration"=>12325, "position"=>0},
      {"title"=>"Discussion", "duration"=>655325, "position"=>12325}
    ]
###Set chapters
Setting the chapters is just as simple:

    require 'chapter'
    chapters = [{"title"=>"Introduction", "duration"=>12325},
      {"title"=>"Discussion", "duration"=>655325}]
    Chapters.set_chapters("/path/fo/file.m4a", chapters)
**CAUTON**: `set_chapters` will overwrite any existing chapters in the file.

##Copyright
###The MIT Licence
Copyright (c) 2012 Pascal Jungblut

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[1]: https://code.google.com/p/mp4v2/
[2]: https://code.google.com/p/mp4v2/wiki/BuildSource
