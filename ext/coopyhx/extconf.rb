require 'mkmf'

puts Dir.pwd
find_header('coopyhx_rb.h', 'include', 'coopyhx/include', Dir.pwd + '/../../../../ext/coopyhx/include')

$defs.push("-DHX_LINUX -DHXCPP_VISIT_ALLOCS -Dhaxe3 -DHXCPP_FORCE_OBJ_MAP")

create_makefile('coopyhx/coopyhx')
