Gem::Specification.new do |s|
  s.name               = "coopyhx"
  s.version            = "0.1"
  # s.default_executable = "sqlite_diff"
  # s.executables << 'sqlite_diff'

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Paul Fitzpatrick"]
  s.date = %q{2012-04-10}
  s.description = %q{Coopyhx!}
  s.email = %q{paul@robotrebuilt.com}
  s.files = `find ext -iname "*.cpp"`.split
  s.files.concat(`find ext -iname "*.h"`.split)
  s.files << "Rakefile"
  puts s.files
  s.test_files = ["test/test_coopy.rb"]
  s.homepage = %q{https://github.com/paulfitz/coopyhx}
  # s.require_paths = ["lib"]
  s.rubygems_version = %q{1.6.2}
  s.summary = %q{Coopyhx - hx fork of coopy}
  # s.add_dependency('sqlite3') # dependency seems to do more harm than good

  s.extensions = ['ext/coopyhx/extconf.rb']
	     
  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
    else
    end
  else
  end
end

