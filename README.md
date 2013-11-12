coopyhx, just enough packaging for internal use on growrows.com

Notes to self on how to keep this gem up to date.  First, get the `cpp` version of coopyhx:

   * Make sure haxe is up to date
   * Make sure hxcpp is up to date
   * Checkout coopyhx
   * in coopyhx "./packaging/cpp_recipe/build_cpp_package.sh mypack"
   * If all goes well, everything we need ends up in `mypack/build/coopyhx_cpp.zip`

Now, back here, we do:

````
rm -rf unpack # make sure this cache directory is gone
./prepare.sh coopyhx_cpp.zip
gem build coopyhx.gemspec && GEM_HOME=/tmp gem install coopyhx-0.X.X.gem 
````
