# encoding: utf-8

require 'rubygems'
require 'bundler'
begin
  Bundler.setup(:default, :development)
rescue Bundler::BundlerError => e
  $stderr.puts e.message
  $stderr.puts "Run `bundle install` to install missing gems"
  exit e.status_code
end
require 'rake'

require 'jeweler'
Jeweler::Tasks.new do |gem|
  # gem is a Gem::Specification... see http://docs.rubygems.org/read/chapter/20 for more options
  gem.name = "chapter"
  gem.homepage = "http://github.com/pascalj/chapter"
  gem.license = "MIT"
  gem.summary = %Q{Read and write chapters of mp4 files}
  gem.description = %Q{This very simple gem uses the mp4v2 C library to read and set the chapters of mp4 files.}
  gem.email = "mail@pascal-jungblut.com"
  gem.authors = ["Pascal Jungblut"]
  gem.files = Dir.glob('lib/**/*.rb') + Dir.glob('ext/**/*.{c,h,rb}')
  # dependencies defined in Gemfile
end
Jeweler::RubygemsDotOrgTasks.new


require 'rdoc/task'
Rake::RDocTask.new do |rdoc|
  version = File.exist?('VERSION') ? File.read('VERSION') : ""

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "chapter #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end
