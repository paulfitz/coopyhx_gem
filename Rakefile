require 'rake/testtask'
require 'rake/extensiontask'

gemspec = Gem::Specification.load('coopyhx.gemspec')
Rake::ExtensionTask.new do |ext|
  ext.name = 'coopyhx'
  ext.ext_dir = 'ext/coopyhx'
  ext.lib_dir = 'lib/coopyhx'
  ext.gem_spec = gemspec
end

Rake::TestTask.new do |t|
  t.libs << 'test'
end

task :default => [:compile, :test]

