require 'test/unit'
require 'coopyhx'

class CoopyTest < Test::Unit::TestCase

  def setup
    @t1 = to_table([["Thing","Color"],["Grass","Green"]]);
    @t2 = to_table([["Thing","Color"],["Sky","Blue"],["Grass","Greenish"]]);
  end

  def test_simple_table
    tab = Coopyhx::SimpleTable.new(20,10)
    assert_equal(tab.get_width,20)
    assert_equal(tab.get_height,10)
    tab.setCell(1,3,15)
    tab.setCell(2,3,"hello")
    assert_equal(15,tab.getCell(1,3).asInt)
    assert_equal("hello",tab.getCell(2,3).toString.c_str)
  end

  def test_alignment
    alignment = Coopyhx::Coopy.compareTables(@t1.asTable,@t2.asTable).align
    assert_equal(alignment.a2b(0).asInt,0)
    assert_equal(alignment.a2b(1).asInt,2)
  end

  def test_highlight
    alignment = Coopyhx::Coopy.compareTables(@t1.asTable,@t2.asTable).align
    highlighter = Coopyhx::TableDiff.new(alignment,Coopyhx::CompareFlags.new())
    out = Coopyhx::SimpleTable.new(0,0)
    highlighter.hilite(out.asTable)
    result = from_table(out)
    assert_equal(result[0][0],"@@")
    assert_equal(result[1][0],"+++")
    assert_equal(result[2][0],"->")
    assert_equal(result[2][2],"Green->Greenish")
  end

  def test_highlight_render
    alignment = Coopyhx::Coopy.compareTables(@t1.asTable,@t2.asTable).align
    highlighter = Coopyhx::TableDiff.new(alignment,Coopyhx::CompareFlags.new())
    out = Coopyhx::SimpleTable.new(0,0)
    highlighter.hilite(out.asTable)
    diff2html = Coopyhx::DiffRender.new
    diff2html.render(out.asTable)
    txt = diff2html.html.c_str
    assert_match /<table>/, txt
    assert_match /<td>/, txt
  end

  def test_patch
    alignment = Coopyhx::Coopy.compareTables(@t1.asTable,@t2.asTable).align
    highlighter = Coopyhx::TableDiff.new(alignment,Coopyhx::CompareFlags.new())
    out = Coopyhx::SimpleTable.new(0,0)
    highlighter.hilite(out.asTable)
    t1a = to_table([["Thing","Color"],["Grass","Green"]])
    patcher = Coopyhx::HighlightPatch.new(t1a.asTable,out.asTable)
    patcher.apply
    result = from_table(t1a)
    assert_equal(result[0][0],"Thing")
    assert_equal(result[1][0],"Sky")
    assert_equal(result[2][0],"Grass")
    assert_equal(result[2][1],"Greenish")
  end

private

  # I should write a native table adapter, but for now
  # we pay the copy-tax
  def to_table(lst)
    h = lst.length || 0
    w = lst.map{|x| x.length}.max || 0
    tab = Coopyhx::SimpleTable.new(w,h)
    lst.each_with_index do |row,i|
      row.each_with_index do |cell,j|
        tab.setCell(j,i,cell) unless cell.nil?
      end
    end
    tab
  end

  # I should write a native table adapter, but for now
  # we pay the copy-tax
  def from_table(tab)
    h = tab.get_height
    w = tab.get_width
    v = tab.getCellView
    lst = []
    for y in 0..(h-1)
      row = []
      for x in 0..(w-1)
        cell = tab.getCell(x,y)
        cell = v.toString(cell).to_s unless cell.nil?
        row << cell
      end
      lst << row
    end
    lst
  end
end
