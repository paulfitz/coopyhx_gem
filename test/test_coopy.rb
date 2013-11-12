require 'test/unit'
require 'coopyhx'

class CoopyTest < Test::Unit::TestCase

  def test_basic
    tab = Coopyhx::SimpleTable.new(20,10)
    tab.setCell(1,3,15)
    tab.setCell(2,3,"hello")
    v = tab.getCellView
    assert_equal(15,tab.getCell(1,3).asInt)
    assert_equal("hello",tab.getCell(2,3).toString.c_str)
  end

end
