#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_CompareFlags
#include <coopy/CompareFlags.h>
#endif
#ifndef INCLUDED_coopy_Mover
#include <coopy/Mover.h>
#endif
#ifndef INCLUDED_coopy_Ordering
#include <coopy/Ordering.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_TableDiff
#include <coopy/TableDiff.h>
#endif
#ifndef INCLUDED_coopy_Unit
#include <coopy/Unit.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
namespace coopy{

Void TableDiff_obj::__construct(::coopy::Alignment align,::coopy::CompareFlags flags)
{
HX_STACK_FRAME("coopy.TableDiff","new",0x9c7656a3,"coopy.TableDiff.new","coopy/TableDiff.hx",12,0xda8b0bae)

HX_STACK_ARG(align,"align")

HX_STACK_ARG(flags,"flags")
{
	HX_STACK_LINE(13)
	this->align = align;
	HX_STACK_LINE(14)
	this->flags = flags;
}
;
	return null();
}

TableDiff_obj::~TableDiff_obj() { }

Dynamic TableDiff_obj::__CreateEmpty() { return  new TableDiff_obj; }
hx::ObjectPtr< TableDiff_obj > TableDiff_obj::__new(::coopy::Alignment align,::coopy::CompareFlags flags)
{  hx::ObjectPtr< TableDiff_obj > result = new TableDiff_obj();
	result->__construct(align,flags);
	return result;}

Dynamic TableDiff_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TableDiff_obj > result = new TableDiff_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String TableDiff_obj::getSeparator( ::coopy::Table t,::coopy::Table t2,::String root){
	HX_STACK_FRAME("coopy.TableDiff","getSeparator",0x5eb0164c,"coopy.TableDiff.getSeparator","coopy/TableDiff.hx",18,0xda8b0bae)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(t2,"t2")
	HX_STACK_ARG(root,"root")
	HX_STACK_LINE(19)
	::String sep = root;		HX_STACK_VAR(sep,"sep");
	HX_STACK_LINE(20)
	int w = t->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(21)
	int h = t->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(22)
	::coopy::View view = t->getCellView();		HX_STACK_VAR(view,"view");
	HX_STACK_LINE(23)
	{
		HX_STACK_LINE(23)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(23)
		while(((_g < h))){
			HX_STACK_LINE(23)
			int y = (_g)++;		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(24)
			{
				HX_STACK_LINE(24)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(24)
				while(((_g1 < w))){
					HX_STACK_LINE(24)
					int x = (_g1)++;		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(25)
					::String txt = view->toString(t->getCell(x,y));		HX_STACK_VAR(txt,"txt");
					HX_STACK_LINE(26)
					if (((txt == null()))){
						HX_STACK_LINE(26)
						continue;
					}
					HX_STACK_LINE(27)
					while(((txt.indexOf(sep,null()) >= (int)0))){
						HX_STACK_LINE(28)
						sep = (HX_CSTRING("-") + sep);
					}
				}
			}
		}
	}
	HX_STACK_LINE(32)
	if (((t2 != null()))){
		HX_STACK_LINE(33)
		w = t2->__Field(HX_CSTRING("get_width"),true)();
		HX_STACK_LINE(34)
		h = t2->__Field(HX_CSTRING("get_height"),true)();
		HX_STACK_LINE(35)
		{
			HX_STACK_LINE(35)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(35)
			while(((_g < h))){
				HX_STACK_LINE(35)
				int y = (_g)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(36)
				{
					HX_STACK_LINE(36)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(36)
					while(((_g1 < w))){
						HX_STACK_LINE(36)
						int x = (_g1)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(37)
						::String txt = view->toString(t2->getCell(x,y));		HX_STACK_VAR(txt,"txt");
						HX_STACK_LINE(38)
						if (((txt == null()))){
							HX_STACK_LINE(38)
							continue;
						}
						HX_STACK_LINE(39)
						while(((txt.indexOf(sep,null()) >= (int)0))){
							HX_STACK_LINE(40)
							sep = (HX_CSTRING("-") + sep);
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(45)
	return sep;
}


HX_DEFINE_DYNAMIC_FUNC3(TableDiff_obj,getSeparator,return )

::String TableDiff_obj::quoteForDiff( ::coopy::View v,Dynamic d){
	HX_STACK_FRAME("coopy.TableDiff","quoteForDiff",0x2101452f,"coopy.TableDiff.quoteForDiff","coopy/TableDiff.hx",48,0xda8b0bae)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(49)
	::String nil = HX_CSTRING("NULL");		HX_STACK_VAR(nil,"nil");
	HX_STACK_LINE(50)
	if ((v->equals(d,null()))){
		HX_STACK_LINE(51)
		return nil;
	}
	HX_STACK_LINE(53)
	::String str = v->toString(d);		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(54)
	int score = (int)0;		HX_STACK_VAR(score,"score");
	HX_STACK_LINE(55)
	{
		HX_STACK_LINE(55)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(55)
		int _g = str.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(55)
		while(((_g1 < _g))){
			HX_STACK_LINE(55)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(56)
			if (((str.charCodeAt(score) != (int)95))){
				HX_STACK_LINE(56)
				break;
			}
			HX_STACK_LINE(57)
			(score)++;
		}
	}
	HX_STACK_LINE(59)
	if (((str.substr(score,null()) == nil))){
		HX_STACK_LINE(60)
		str = (HX_CSTRING("_") + str);
	}
	HX_STACK_LINE(62)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC2(TableDiff_obj,quoteForDiff,return )

bool TableDiff_obj::isReordered( ::haxe::ds::IntMap m,int ct){
	HX_STACK_FRAME("coopy.TableDiff","isReordered",0xf2d88913,"coopy.TableDiff.isReordered","coopy/TableDiff.hx",65,0xda8b0bae)
	HX_STACK_THIS(this)
	HX_STACK_ARG(m,"m")
	HX_STACK_ARG(ct,"ct")
	HX_STACK_LINE(66)
	bool reordered = false;		HX_STACK_VAR(reordered,"reordered");
	HX_STACK_LINE(67)
	int l = (int)-1;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(68)
	int r = (int)-1;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(69)
	{
		HX_STACK_LINE(69)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(69)
		while(((_g < ct))){
			HX_STACK_LINE(69)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(70)
			::coopy::Unit unit = m->get(i);		HX_STACK_VAR(unit,"unit");
			HX_STACK_LINE(71)
			if (((unit == null()))){
				HX_STACK_LINE(71)
				continue;
			}
			HX_STACK_LINE(72)
			if (((unit->l >= (int)0))){
				HX_STACK_LINE(73)
				if (((unit->l < l))){
					HX_STACK_LINE(74)
					reordered = true;
					HX_STACK_LINE(75)
					break;
				}
				HX_STACK_LINE(77)
				l = unit->l;
			}
			HX_STACK_LINE(79)
			if (((unit->r >= (int)0))){
				HX_STACK_LINE(80)
				if (((unit->r < r))){
					HX_STACK_LINE(81)
					reordered = true;
					HX_STACK_LINE(82)
					break;
				}
				HX_STACK_LINE(84)
				r = unit->r;
			}
		}
	}
	HX_STACK_LINE(87)
	return reordered;
}


HX_DEFINE_DYNAMIC_FUNC2(TableDiff_obj,isReordered,return )

Void TableDiff_obj::spreadContext( Array< ::Dynamic > units,int del,Array< int > active){
{
		HX_STACK_FRAME("coopy.TableDiff","spreadContext",0x869797bf,"coopy.TableDiff.spreadContext","coopy/TableDiff.hx",94,0xda8b0bae)
		HX_STACK_THIS(this)
		HX_STACK_ARG(units,"units")
		HX_STACK_ARG(del,"del")
		HX_STACK_ARG(active,"active")
		HX_STACK_LINE(94)
		if (((bool((del > (int)0)) && bool((active != null()))))){
			HX_STACK_LINE(96)
			int mark = (-(del) - (int)1);		HX_STACK_VAR(mark,"mark");
			HX_STACK_LINE(97)
			int skips = (int)0;		HX_STACK_VAR(skips,"skips");
			HX_STACK_LINE(98)
			{
				HX_STACK_LINE(98)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(98)
				int _g = units->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(98)
				while(((_g1 < _g))){
					HX_STACK_LINE(98)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(99)
					if (((active->__get(i) == (int)-3))){
						HX_STACK_LINE(101)
						(skips)++;
						HX_STACK_LINE(102)
						continue;
					}
					HX_STACK_LINE(104)
					if (((bool((active->__get(i) == (int)0)) || bool((active->__get(i) == (int)3))))){
						HX_STACK_LINE(105)
						if ((((i - mark) <= (del + skips)))){
							HX_STACK_LINE(106)
							active[i] = (int)2;
						}
						else{
							HX_STACK_LINE(107)
							if ((((i - mark) == ((del + (int)1) + skips)))){
								HX_STACK_LINE(108)
								active[i] = (int)3;
							}
						}
					}
					else{
						HX_STACK_LINE(110)
						if (((active->__get(i) == (int)1))){
							HX_STACK_LINE(111)
							mark = i;
							HX_STACK_LINE(112)
							skips = (int)0;
						}
					}
				}
			}
			HX_STACK_LINE(117)
			mark = ((units->length + del) + (int)1);
			HX_STACK_LINE(118)
			skips = (int)0;
			HX_STACK_LINE(119)
			{
				HX_STACK_LINE(119)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(119)
				int _g = units->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(119)
				while(((_g1 < _g))){
					HX_STACK_LINE(119)
					int j = (_g1)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(120)
					int i = ((units->length - (int)1) - j);		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(121)
					if (((active->__get(i) == (int)-3))){
						HX_STACK_LINE(123)
						(skips)++;
						HX_STACK_LINE(124)
						continue;
					}
					HX_STACK_LINE(126)
					if (((bool((active->__get(i) == (int)0)) || bool((active->__get(i) == (int)3))))){
						HX_STACK_LINE(127)
						if ((((mark - i) <= (del + skips)))){
							HX_STACK_LINE(128)
							active[i] = (int)2;
						}
						else{
							HX_STACK_LINE(129)
							if ((((mark - i) == ((del + (int)1) + skips)))){
								HX_STACK_LINE(130)
								active[i] = (int)3;
							}
						}
					}
					else{
						HX_STACK_LINE(132)
						if (((active->__get(i) == (int)1))){
							HX_STACK_LINE(133)
							mark = i;
							HX_STACK_LINE(134)
							skips = (int)0;
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TableDiff_obj,spreadContext,(void))

::String TableDiff_obj::reportUnit( ::coopy::Unit unit){
	HX_STACK_FRAME("coopy.TableDiff","reportUnit",0xec03b575,"coopy.TableDiff.reportUnit","coopy/TableDiff.hx",140,0xda8b0bae)
	HX_STACK_THIS(this)
	HX_STACK_ARG(unit,"unit")
	HX_STACK_LINE(141)
	::String txt = unit->toString();		HX_STACK_VAR(txt,"txt");
	HX_STACK_LINE(142)
	bool reordered = false;		HX_STACK_VAR(reordered,"reordered");
	HX_STACK_LINE(143)
	if (((unit->l >= (int)0))){
		HX_STACK_LINE(144)
		if (((unit->l < this->l_prev))){
			HX_STACK_LINE(145)
			reordered = true;
		}
		HX_STACK_LINE(147)
		this->l_prev = unit->l;
	}
	HX_STACK_LINE(149)
	if (((unit->r >= (int)0))){
		HX_STACK_LINE(150)
		if (((unit->r < this->r_prev))){
			HX_STACK_LINE(151)
			reordered = true;
		}
		HX_STACK_LINE(153)
		this->r_prev = unit->r;
	}
	HX_STACK_LINE(155)
	if ((reordered)){
		HX_STACK_LINE(155)
		txt = ((HX_CSTRING("[") + txt) + HX_CSTRING("]"));
	}
	HX_STACK_LINE(156)
	return txt;
}


HX_DEFINE_DYNAMIC_FUNC1(TableDiff_obj,reportUnit,return )

bool TableDiff_obj::hilite( ::coopy::Table output){
	HX_STACK_FRAME("coopy.TableDiff","hilite",0x35e2124c,"coopy.TableDiff.hilite","coopy/TableDiff.hx",159,0xda8b0bae)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_LINE(160)
	if ((!(output->isResizable()))){
		HX_STACK_LINE(160)
		return false;
	}
	HX_STACK_LINE(161)
	output->resize((int)0,(int)0);
	HX_STACK_LINE(162)
	output->clear();
	HX_STACK_LINE(164)
	::haxe::ds::IntMap row_map = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(row_map,"row_map");
	HX_STACK_LINE(165)
	::haxe::ds::IntMap col_map = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(col_map,"col_map");
	HX_STACK_LINE(167)
	::coopy::Ordering order = this->align->toOrder();		HX_STACK_VAR(order,"order");
	HX_STACK_LINE(168)
	Array< ::Dynamic > units = order->getList();		HX_STACK_VAR(units,"units");
	HX_STACK_LINE(169)
	bool has_parent = (this->align->reference != null());		HX_STACK_VAR(has_parent,"has_parent");
	HX_STACK_LINE(170)
	::coopy::Table a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(171)
	::coopy::Table b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(172)
	::coopy::Table p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(173)
	int ra_header = (int)0;		HX_STACK_VAR(ra_header,"ra_header");
	HX_STACK_LINE(174)
	int rb_header = (int)0;		HX_STACK_VAR(rb_header,"rb_header");
	HX_STACK_LINE(175)
	::haxe::ds::IntMap is_index_p = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(is_index_p,"is_index_p");
	HX_STACK_LINE(176)
	::haxe::ds::IntMap is_index_a = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(is_index_a,"is_index_a");
	HX_STACK_LINE(177)
	::haxe::ds::IntMap is_index_b = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(is_index_b,"is_index_b");
	HX_STACK_LINE(178)
	if ((has_parent)){
		HX_STACK_LINE(179)
		p = this->align->getSource();
		HX_STACK_LINE(180)
		a = this->align->reference->getTarget();
		HX_STACK_LINE(181)
		b = this->align->getTarget();
		HX_STACK_LINE(182)
		ra_header = this->align->reference->meta->getTargetHeader();
		HX_STACK_LINE(183)
		rb_header = this->align->meta->getTargetHeader();
		HX_STACK_LINE(184)
		if (((this->align->getIndexColumns() != null()))){
			HX_STACK_LINE(185)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(185)
			Array< ::Dynamic > _g1 = this->align->getIndexColumns();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(185)
			while(((_g < _g1->length))){
				HX_STACK_LINE(185)
				::coopy::Unit p2b = _g1->__get(_g).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(p2b,"p2b");
				HX_STACK_LINE(185)
				++(_g);
				HX_STACK_LINE(186)
				if (((p2b->l >= (int)0))){
					HX_STACK_LINE(186)
					is_index_p->set(p2b->l,true);
				}
				HX_STACK_LINE(187)
				if (((p2b->r >= (int)0))){
					HX_STACK_LINE(187)
					is_index_b->set(p2b->r,true);
				}
			}
		}
		HX_STACK_LINE(190)
		if (((this->align->reference->getIndexColumns() != null()))){
			HX_STACK_LINE(191)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(191)
			Array< ::Dynamic > _g1 = this->align->reference->getIndexColumns();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(191)
			while(((_g < _g1->length))){
				HX_STACK_LINE(191)
				::coopy::Unit p2a = _g1->__get(_g).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(p2a,"p2a");
				HX_STACK_LINE(191)
				++(_g);
				HX_STACK_LINE(192)
				if (((p2a->l >= (int)0))){
					HX_STACK_LINE(192)
					is_index_p->set(p2a->l,true);
				}
				HX_STACK_LINE(193)
				if (((p2a->r >= (int)0))){
					HX_STACK_LINE(193)
					is_index_a->set(p2a->r,true);
				}
			}
		}
	}
	else{
		HX_STACK_LINE(197)
		a = this->align->getSource();
		HX_STACK_LINE(198)
		b = this->align->getTarget();
		HX_STACK_LINE(199)
		p = a;
		HX_STACK_LINE(200)
		ra_header = this->align->meta->getSourceHeader();
		HX_STACK_LINE(201)
		rb_header = this->align->meta->getTargetHeader();
		HX_STACK_LINE(202)
		if (((this->align->getIndexColumns() != null()))){
			HX_STACK_LINE(203)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(203)
			Array< ::Dynamic > _g1 = this->align->getIndexColumns();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(203)
			while(((_g < _g1->length))){
				HX_STACK_LINE(203)
				::coopy::Unit a2b = _g1->__get(_g).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(a2b,"a2b");
				HX_STACK_LINE(203)
				++(_g);
				HX_STACK_LINE(204)
				if (((a2b->l >= (int)0))){
					HX_STACK_LINE(204)
					is_index_a->set(a2b->l,true);
				}
				HX_STACK_LINE(205)
				if (((a2b->r >= (int)0))){
					HX_STACK_LINE(205)
					is_index_b->set(a2b->r,true);
				}
			}
		}
	}
	HX_STACK_LINE(210)
	::coopy::Ordering column_order = this->align->meta->toOrder();		HX_STACK_VAR(column_order,"column_order");
	HX_STACK_LINE(211)
	Array< ::Dynamic > column_units = column_order->getList();		HX_STACK_VAR(column_units,"column_units");
	HX_STACK_LINE(213)
	bool show_rc_numbers = false;		HX_STACK_VAR(show_rc_numbers,"show_rc_numbers");
	HX_STACK_LINE(214)
	::haxe::ds::IntMap row_moves = null();		HX_STACK_VAR(row_moves,"row_moves");
	HX_STACK_LINE(215)
	::haxe::ds::IntMap col_moves = null();		HX_STACK_VAR(col_moves,"col_moves");
	HX_STACK_LINE(216)
	if ((this->flags->ordered)){
		HX_STACK_LINE(217)
		row_moves = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(218)
		Array< int > moves = ::coopy::Mover_obj::moveUnits(units);		HX_STACK_VAR(moves,"moves");
		HX_STACK_LINE(219)
		{
			HX_STACK_LINE(219)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(219)
			int _g = moves->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(219)
			while(((_g1 < _g))){
				HX_STACK_LINE(219)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(220)
				{
					HX_STACK_LINE(220)
					row_moves->set(moves->__get(i),i);
					HX_STACK_LINE(220)
					i;
				}
			}
		}
		HX_STACK_LINE(222)
		col_moves = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(223)
		moves = ::coopy::Mover_obj::moveUnits(column_units);
		HX_STACK_LINE(224)
		{
			HX_STACK_LINE(224)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(224)
			int _g = moves->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(224)
			while(((_g1 < _g))){
				HX_STACK_LINE(224)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(225)
				{
					HX_STACK_LINE(225)
					col_moves->set(moves->__get(i),i);
					HX_STACK_LINE(225)
					i;
				}
			}
		}
	}
	HX_STACK_LINE(229)
	Array< int > active = Array_obj< int >::__new();		HX_STACK_VAR(active,"active");
	HX_STACK_LINE(230)
	Array< int > active_column = null();		HX_STACK_VAR(active_column,"active_column");
	HX_STACK_LINE(231)
	if ((!(this->flags->show_unchanged))){
		HX_STACK_LINE(232)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(232)
		int _g = units->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(232)
		while(((_g1 < _g))){
			HX_STACK_LINE(232)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(233)
			active[i] = (int)0;
		}
	}
	HX_STACK_LINE(237)
	bool allow_insert = this->flags->allowInsert();		HX_STACK_VAR(allow_insert,"allow_insert");
	HX_STACK_LINE(238)
	bool allow_delete = this->flags->allowDelete();		HX_STACK_VAR(allow_delete,"allow_delete");
	HX_STACK_LINE(239)
	bool allow_update = this->flags->allowUpdate();		HX_STACK_VAR(allow_update,"allow_update");
	HX_STACK_LINE(241)
	if ((!(this->flags->show_unchanged_columns))){
		HX_STACK_LINE(242)
		active_column = Array_obj< int >::__new();
		HX_STACK_LINE(243)
		{
			HX_STACK_LINE(243)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(243)
			int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(243)
			while(((_g1 < _g))){
				HX_STACK_LINE(243)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(244)
				int v = (int)0;		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(245)
				::coopy::Unit unit = column_units->__get(i).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(unit,"unit");
				HX_STACK_LINE(246)
				if (((bool((unit->l >= (int)0)) && bool(is_index_a->get(unit->l))))){
					HX_STACK_LINE(246)
					v = (int)1;
				}
				HX_STACK_LINE(247)
				if (((bool((unit->r >= (int)0)) && bool(is_index_b->get(unit->r))))){
					HX_STACK_LINE(247)
					v = (int)1;
				}
				HX_STACK_LINE(248)
				if (((bool((unit->p >= (int)0)) && bool(is_index_p->get(unit->p))))){
					HX_STACK_LINE(248)
					v = (int)1;
				}
				HX_STACK_LINE(249)
				active_column[i] = v;
			}
		}
	}
	HX_STACK_LINE(254)
	int outer_reps_needed;		HX_STACK_VAR(outer_reps_needed,"outer_reps_needed");
	HX_STACK_LINE(254)
	if (((bool(this->flags->show_unchanged) && bool(this->flags->show_unchanged_columns)))){
		HX_STACK_LINE(254)
		outer_reps_needed = (int)1;
	}
	else{
		HX_STACK_LINE(254)
		outer_reps_needed = (int)2;
	}
	HX_STACK_LINE(256)
	::coopy::View v = a->getCellView();		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(257)
	::String sep = HX_CSTRING("");		HX_STACK_VAR(sep,"sep");
	HX_STACK_LINE(258)
	::String conflict_sep = HX_CSTRING("");		HX_STACK_VAR(conflict_sep,"conflict_sep");
	HX_STACK_LINE(260)
	Array< ::String > schema = Array_obj< ::String >::__new();		HX_STACK_VAR(schema,"schema");
	HX_STACK_LINE(261)
	bool have_schema = false;		HX_STACK_VAR(have_schema,"have_schema");
	HX_STACK_LINE(262)
	{
		HX_STACK_LINE(262)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(262)
		int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(262)
		while(((_g1 < _g))){
			HX_STACK_LINE(262)
			int j = (_g1)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(263)
			::coopy::Unit cunit = column_units->__get(j).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(cunit,"cunit");
			HX_STACK_LINE(264)
			bool reordered = false;		HX_STACK_VAR(reordered,"reordered");
			HX_STACK_LINE(266)
			if ((this->flags->ordered)){
				HX_STACK_LINE(267)
				if ((col_moves->exists(j))){
					HX_STACK_LINE(268)
					reordered = true;
				}
				HX_STACK_LINE(270)
				if ((reordered)){
					HX_STACK_LINE(270)
					show_rc_numbers = true;
				}
			}
			HX_STACK_LINE(273)
			::String act = HX_CSTRING("");		HX_STACK_VAR(act,"act");
			HX_STACK_LINE(274)
			if (((bool((cunit->r >= (int)0)) && bool((cunit->lp() == (int)-1))))){
				HX_STACK_LINE(275)
				have_schema = true;
				HX_STACK_LINE(276)
				act = HX_CSTRING("+++");
				HX_STACK_LINE(277)
				if (((active_column != null()))){
					HX_STACK_LINE(278)
					if ((allow_update)){
						HX_STACK_LINE(278)
						active_column[j] = (int)1;
					}
				}
			}
			HX_STACK_LINE(281)
			if (((bool((cunit->r < (int)0)) && bool((cunit->lp() >= (int)0))))){
				HX_STACK_LINE(282)
				have_schema = true;
				HX_STACK_LINE(283)
				act = HX_CSTRING("---");
				HX_STACK_LINE(284)
				if (((active_column != null()))){
					HX_STACK_LINE(285)
					if ((allow_update)){
						HX_STACK_LINE(285)
						active_column[j] = (int)1;
					}
				}
			}
			HX_STACK_LINE(288)
			if (((bool((cunit->r >= (int)0)) && bool((cunit->lp() >= (int)0))))){
				HX_STACK_LINE(289)
				if (((bool((a->__Field(HX_CSTRING("get_height"),true)() >= ra_header)) && bool((b->__Field(HX_CSTRING("get_height"),true)() >= rb_header))))){
					HX_STACK_LINE(290)
					Dynamic aa = a->getCell(cunit->lp(),ra_header);		HX_STACK_VAR(aa,"aa");
					HX_STACK_LINE(291)
					Dynamic bb = b->getCell(cunit->r,rb_header);		HX_STACK_VAR(bb,"bb");
					HX_STACK_LINE(292)
					if ((!(v->equals(aa,bb)))){
						HX_STACK_LINE(293)
						have_schema = true;
						HX_STACK_LINE(294)
						act = HX_CSTRING("(");
						HX_STACK_LINE(295)
						hx::AddEq(act,v->toString(aa));
						HX_STACK_LINE(296)
						hx::AddEq(act,HX_CSTRING(")"));
						HX_STACK_LINE(297)
						if (((active_column != null()))){
							HX_STACK_LINE(297)
							active_column[j] = (int)1;
						}
					}
				}
			}
			HX_STACK_LINE(301)
			if ((reordered)){
				HX_STACK_LINE(302)
				act = (HX_CSTRING(":") + act);
				HX_STACK_LINE(303)
				have_schema = true;
				HX_STACK_LINE(304)
				if (((active_column != null()))){
					HX_STACK_LINE(304)
					active_column = null();
				}
			}
			HX_STACK_LINE(307)
			schema->push(act);
		}
	}
	HX_STACK_LINE(309)
	if ((have_schema)){
		HX_STACK_LINE(310)
		int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(311)
		output->resize((column_units->length + (int)1),(at + (int)1));
		HX_STACK_LINE(312)
		output->setCell((int)0,at,v->toDatum(HX_CSTRING("!")));
		HX_STACK_LINE(313)
		{
			HX_STACK_LINE(313)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(313)
			int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(313)
			while(((_g1 < _g))){
				HX_STACK_LINE(313)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(314)
				output->setCell((j + (int)1),at,v->toDatum(schema->__get(j)));
			}
		}
	}
	HX_STACK_LINE(318)
	bool top_line_done = false;		HX_STACK_VAR(top_line_done,"top_line_done");
	HX_STACK_LINE(319)
	if ((this->flags->always_show_header)){
		HX_STACK_LINE(320)
		int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(321)
		output->resize((column_units->length + (int)1),(at + (int)1));
		HX_STACK_LINE(322)
		output->setCell((int)0,at,v->toDatum(HX_CSTRING("@@")));
		HX_STACK_LINE(323)
		{
			HX_STACK_LINE(323)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(323)
			int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(323)
			while(((_g1 < _g))){
				HX_STACK_LINE(323)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(324)
				::coopy::Unit cunit = column_units->__get(j).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(cunit,"cunit");
				HX_STACK_LINE(325)
				if (((cunit->r >= (int)0))){
					HX_STACK_LINE(326)
					if (((b->__Field(HX_CSTRING("get_height"),true)() > (int)0))){
						HX_STACK_LINE(327)
						output->setCell((j + (int)1),at,b->getCell(cunit->r,rb_header));
					}
				}
				else{
					HX_STACK_LINE(330)
					if (((cunit->lp() >= (int)0))){
						HX_STACK_LINE(331)
						if (((a->__Field(HX_CSTRING("get_height"),true)() > (int)0))){
							HX_STACK_LINE(332)
							output->setCell((j + (int)1),at,a->getCell(cunit->lp(),ra_header));
						}
					}
				}
				HX_STACK_LINE(336)
				col_map->set((j + (int)1),cunit);
			}
		}
		HX_STACK_LINE(338)
		top_line_done = true;
	}
	HX_STACK_LINE(342)
	{
		HX_STACK_LINE(342)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(342)
		while(((_g < outer_reps_needed))){
			HX_STACK_LINE(342)
			int out = (_g)++;		HX_STACK_VAR(out,"out");
			HX_STACK_LINE(343)
			if (((out == (int)1))){
				HX_STACK_LINE(344)
				this->spreadContext(units,this->flags->unchanged_context,active);
				HX_STACK_LINE(345)
				this->spreadContext(column_units,this->flags->unchanged_column_context,active_column);
				HX_STACK_LINE(347)
				if (((active_column != null()))){
					HX_STACK_LINE(348)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(348)
					int _g1 = column_units->length;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(348)
					while(((_g2 < _g1))){
						HX_STACK_LINE(348)
						int i = (_g2)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(349)
						if (((active_column->__get(i) == (int)3))){
							HX_STACK_LINE(350)
							active_column[i] = (int)0;
						}
					}
				}
			}
			HX_STACK_LINE(356)
			bool showed_dummy = false;		HX_STACK_VAR(showed_dummy,"showed_dummy");
			HX_STACK_LINE(357)
			int l = (int)-1;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(358)
			int r = (int)-1;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(359)
			{
				HX_STACK_LINE(359)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(359)
				int _g1 = units->length;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(359)
				while(((_g2 < _g1))){
					HX_STACK_LINE(359)
					int i = (_g2)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(360)
					::coopy::Unit unit = units->__get(i).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(unit,"unit");
					HX_STACK_LINE(361)
					bool reordered = false;		HX_STACK_VAR(reordered,"reordered");
					HX_STACK_LINE(363)
					if ((this->flags->ordered)){
						HX_STACK_LINE(364)
						if ((row_moves->exists(i))){
							HX_STACK_LINE(365)
							reordered = true;
						}
						HX_STACK_LINE(367)
						if ((reordered)){
							HX_STACK_LINE(367)
							show_rc_numbers = true;
						}
					}
					HX_STACK_LINE(370)
					if (((bool((unit->r < (int)0)) && bool((unit->l < (int)0))))){
						HX_STACK_LINE(370)
						continue;
					}
					HX_STACK_LINE(372)
					if (((bool((bool((unit->r == (int)0)) && bool((unit->lp() == (int)0)))) && bool(top_line_done)))){
						HX_STACK_LINE(372)
						continue;
					}
					HX_STACK_LINE(374)
					::String act = HX_CSTRING("");		HX_STACK_VAR(act,"act");
					HX_STACK_LINE(376)
					if ((reordered)){
						HX_STACK_LINE(376)
						act = HX_CSTRING(":");
					}
					HX_STACK_LINE(378)
					bool publish = this->flags->show_unchanged;		HX_STACK_VAR(publish,"publish");
					HX_STACK_LINE(379)
					bool dummy = false;		HX_STACK_VAR(dummy,"dummy");
					HX_STACK_LINE(380)
					if (((out == (int)1))){
						HX_STACK_LINE(381)
						publish = (active->__get(i) > (int)0);
						HX_STACK_LINE(382)
						dummy = (active->__get(i) == (int)3);
						HX_STACK_LINE(383)
						if (((bool(dummy) && bool(showed_dummy)))){
							HX_STACK_LINE(383)
							continue;
						}
						HX_STACK_LINE(384)
						if ((!(publish))){
							HX_STACK_LINE(384)
							continue;
						}
					}
					HX_STACK_LINE(387)
					if ((!(dummy))){
						HX_STACK_LINE(387)
						showed_dummy = false;
					}
					HX_STACK_LINE(389)
					int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
					HX_STACK_LINE(390)
					if ((publish)){
						HX_STACK_LINE(391)
						output->resize((column_units->length + (int)1),(at + (int)1));
					}
					HX_STACK_LINE(394)
					if ((dummy)){
						HX_STACK_LINE(395)
						{
							HX_STACK_LINE(395)
							int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(395)
							int _g3 = (column_units->length + (int)1);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(395)
							while(((_g4 < _g3))){
								HX_STACK_LINE(395)
								int j = (_g4)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(396)
								output->setCell(j,at,v->toDatum(HX_CSTRING("...")));
								HX_STACK_LINE(397)
								showed_dummy = true;
							}
						}
						HX_STACK_LINE(399)
						continue;
					}
					HX_STACK_LINE(402)
					bool have_addition = false;		HX_STACK_VAR(have_addition,"have_addition");
					HX_STACK_LINE(403)
					bool skip = false;		HX_STACK_VAR(skip,"skip");
					HX_STACK_LINE(405)
					if (((bool((bool((unit->p < (int)0)) && bool((unit->l < (int)0)))) && bool((unit->r >= (int)0))))){
						HX_STACK_LINE(406)
						if ((!(allow_insert))){
							HX_STACK_LINE(406)
							skip = true;
						}
						HX_STACK_LINE(407)
						act = HX_CSTRING("+++");
					}
					HX_STACK_LINE(409)
					if (((bool((bool(((bool((unit->p >= (int)0)) || bool(!(has_parent))))) && bool((unit->l >= (int)0)))) && bool((unit->r < (int)0))))){
						HX_STACK_LINE(410)
						if ((!(allow_delete))){
							HX_STACK_LINE(410)
							skip = true;
						}
						HX_STACK_LINE(411)
						act = HX_CSTRING("---");
					}
					HX_STACK_LINE(414)
					if ((skip)){
						HX_STACK_LINE(415)
						if ((!(publish))){
							HX_STACK_LINE(416)
							if (((active != null()))){
								HX_STACK_LINE(417)
								active[i] = (int)-3;
							}
						}
						HX_STACK_LINE(420)
						continue;
					}
					HX_STACK_LINE(423)
					{
						HX_STACK_LINE(423)
						int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(423)
						int _g3 = column_units->length;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(423)
						while(((_g4 < _g3))){
							HX_STACK_LINE(423)
							int j = (_g4)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(424)
							::coopy::Unit cunit = column_units->__get(j).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(cunit,"cunit");
							HX_STACK_LINE(425)
							Dynamic pp = null();		HX_STACK_VAR(pp,"pp");
							HX_STACK_LINE(426)
							Dynamic ll = null();		HX_STACK_VAR(ll,"ll");
							HX_STACK_LINE(427)
							Dynamic rr = null();		HX_STACK_VAR(rr,"rr");
							HX_STACK_LINE(428)
							Dynamic dd = null();		HX_STACK_VAR(dd,"dd");
							HX_STACK_LINE(429)
							Dynamic dd_to = null();		HX_STACK_VAR(dd_to,"dd_to");
							HX_STACK_LINE(430)
							bool have_dd_to = false;		HX_STACK_VAR(have_dd_to,"have_dd_to");
							HX_STACK_LINE(431)
							Dynamic dd_to_alt = null();		HX_STACK_VAR(dd_to_alt,"dd_to_alt");
							HX_STACK_LINE(432)
							bool have_dd_to_alt = false;		HX_STACK_VAR(have_dd_to_alt,"have_dd_to_alt");
							HX_STACK_LINE(433)
							bool have_pp = false;		HX_STACK_VAR(have_pp,"have_pp");
							HX_STACK_LINE(434)
							bool have_ll = false;		HX_STACK_VAR(have_ll,"have_ll");
							HX_STACK_LINE(435)
							bool have_rr = false;		HX_STACK_VAR(have_rr,"have_rr");
							HX_STACK_LINE(436)
							if (((bool((cunit->p >= (int)0)) && bool((unit->p >= (int)0))))){
								HX_STACK_LINE(437)
								pp = p->getCell(cunit->p,unit->p);
								HX_STACK_LINE(438)
								have_pp = true;
							}
							HX_STACK_LINE(440)
							if (((bool((cunit->l >= (int)0)) && bool((unit->l >= (int)0))))){
								HX_STACK_LINE(441)
								ll = a->getCell(cunit->l,unit->l);
								HX_STACK_LINE(442)
								have_ll = true;
							}
							HX_STACK_LINE(444)
							if (((bool((cunit->r >= (int)0)) && bool((unit->r >= (int)0))))){
								HX_STACK_LINE(445)
								rr = b->getCell(cunit->r,unit->r);
								HX_STACK_LINE(446)
								have_rr = true;
								HX_STACK_LINE(447)
								if (((((  ((have_pp)) ? int(cunit->p) : int(cunit->l) )) < (int)0))){
									HX_STACK_LINE(448)
									if (((rr != null()))){
										HX_STACK_LINE(449)
										if (((v->toString(rr) != HX_CSTRING("")))){
											HX_STACK_LINE(450)
											if ((this->flags->allowUpdate())){
												HX_STACK_LINE(451)
												have_addition = true;
											}
										}
									}
								}
							}
							HX_STACK_LINE(459)
							if ((have_pp)){
								HX_STACK_LINE(460)
								if ((!(have_rr))){
									HX_STACK_LINE(461)
									dd = pp;
								}
								else{
									HX_STACK_LINE(464)
									if ((v->equals(pp,rr))){
										HX_STACK_LINE(465)
										dd = pp;
									}
									else{
										HX_STACK_LINE(468)
										dd = pp;
										HX_STACK_LINE(469)
										dd_to = rr;
										HX_STACK_LINE(470)
										have_dd_to = true;
										HX_STACK_LINE(472)
										if ((!(v->equals(pp,ll)))){
											HX_STACK_LINE(473)
											if ((!(v->equals(pp,rr)))){
												HX_STACK_LINE(474)
												dd_to_alt = ll;
												HX_STACK_LINE(475)
												have_dd_to_alt = true;
											}
										}
									}
								}
							}
							else{
								HX_STACK_LINE(480)
								if ((have_ll)){
									HX_STACK_LINE(481)
									if ((!(have_rr))){
										HX_STACK_LINE(482)
										dd = ll;
									}
									else{
										HX_STACK_LINE(484)
										if ((v->equals(ll,rr))){
											HX_STACK_LINE(485)
											dd = ll;
										}
										else{
											HX_STACK_LINE(488)
											dd = ll;
											HX_STACK_LINE(489)
											dd_to = rr;
											HX_STACK_LINE(490)
											have_dd_to = true;
										}
									}
								}
								else{
									HX_STACK_LINE(494)
									dd = rr;
								}
							}
							HX_STACK_LINE(497)
							::String txt = null();		HX_STACK_VAR(txt,"txt");
							HX_STACK_LINE(498)
							if (((bool(have_dd_to) && bool(allow_update)))){
								HX_STACK_LINE(499)
								if (((active_column != null()))){
									HX_STACK_LINE(500)
									active_column[j] = (int)1;
								}
								HX_STACK_LINE(502)
								txt = this->quoteForDiff(v,dd);
								HX_STACK_LINE(504)
								if (((sep == HX_CSTRING("")))){
									HX_STACK_LINE(507)
									sep = this->getSeparator(a,b,HX_CSTRING("->"));
								}
								HX_STACK_LINE(509)
								bool is_conflict = false;		HX_STACK_VAR(is_conflict,"is_conflict");
								HX_STACK_LINE(510)
								if ((have_dd_to_alt)){
									HX_STACK_LINE(511)
									if ((!(v->equals(dd_to,dd_to_alt)))){
										HX_STACK_LINE(512)
										is_conflict = true;
									}
								}
								HX_STACK_LINE(515)
								if ((!(is_conflict))){
									HX_STACK_LINE(516)
									txt = ((txt + sep) + this->quoteForDiff(v,dd_to));
									HX_STACK_LINE(517)
									if (((sep.length > act.length))){
										HX_STACK_LINE(518)
										act = sep;
									}
								}
								else{
									HX_STACK_LINE(521)
									if (((conflict_sep == HX_CSTRING("")))){
										HX_STACK_LINE(522)
										conflict_sep = (this->getSeparator(p,a,HX_CSTRING("!")) + sep);
									}
									HX_STACK_LINE(524)
									txt = ((((txt + conflict_sep) + this->quoteForDiff(v,dd_to_alt)) + conflict_sep) + this->quoteForDiff(v,dd_to));
									HX_STACK_LINE(527)
									act = conflict_sep;
								}
							}
							HX_STACK_LINE(530)
							if (((bool((act == HX_CSTRING(""))) && bool(have_addition)))){
								HX_STACK_LINE(531)
								act = HX_CSTRING("+");
							}
							HX_STACK_LINE(533)
							if (((act == HX_CSTRING("+++")))){
								HX_STACK_LINE(534)
								if ((have_rr)){
									HX_STACK_LINE(535)
									if (((active_column != null()))){
										HX_STACK_LINE(536)
										active_column[j] = (int)1;
									}
								}
							}
							HX_STACK_LINE(540)
							if ((publish)){
								HX_STACK_LINE(541)
								if (((bool((active_column == null())) || bool((active_column->__get(j) > (int)0))))){
									HX_STACK_LINE(542)
									if (((txt != null()))){
										HX_STACK_LINE(543)
										output->setCell((j + (int)1),at,v->toDatum(txt));
									}
									else{
										HX_STACK_LINE(545)
										output->setCell((j + (int)1),at,dd);
									}
								}
							}
						}
					}
					HX_STACK_LINE(551)
					if ((publish)){
						HX_STACK_LINE(552)
						output->setCell((int)0,at,v->toDatum(act));
						HX_STACK_LINE(553)
						row_map->set(at,unit);
					}
					HX_STACK_LINE(555)
					if (((act != HX_CSTRING("")))){
						HX_STACK_LINE(556)
						if ((!(publish))){
							HX_STACK_LINE(557)
							if (((active != null()))){
								HX_STACK_LINE(558)
								active[i] = (int)1;
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(566)
	if ((!(show_rc_numbers))){
		HX_STACK_LINE(567)
		if ((this->flags->always_show_order)){
			HX_STACK_LINE(568)
			show_rc_numbers = true;
		}
		else{
			HX_STACK_LINE(569)
			if ((this->flags->ordered)){
				HX_STACK_LINE(570)
				show_rc_numbers = this->isReordered(row_map,output->__Field(HX_CSTRING("get_height"),true)());
				HX_STACK_LINE(571)
				if ((!(show_rc_numbers))){
					HX_STACK_LINE(572)
					show_rc_numbers = this->isReordered(col_map,output->__Field(HX_CSTRING("get_width"),true)());
				}
			}
		}
	}
	HX_STACK_LINE(577)
	int admin_w = (int)1;		HX_STACK_VAR(admin_w,"admin_w");
	HX_STACK_LINE(578)
	if (((bool(show_rc_numbers) && bool(!(this->flags->never_show_order))))){
		HX_STACK_LINE(579)
		(admin_w)++;
		HX_STACK_LINE(580)
		Array< int > target = Array_obj< int >::__new();		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(581)
		{
			HX_STACK_LINE(581)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(581)
			int _g = output->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(581)
			while(((_g1 < _g))){
				HX_STACK_LINE(581)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(582)
				target->push((i + (int)1));
			}
		}
		HX_STACK_LINE(584)
		output->insertOrDeleteColumns(target,(output->__Field(HX_CSTRING("get_width"),true)() + (int)1));
		HX_STACK_LINE(585)
		this->l_prev = (int)-1;
		HX_STACK_LINE(586)
		this->r_prev = (int)-1;
		HX_STACK_LINE(587)
		{
			HX_STACK_LINE(587)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(587)
			int _g = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(587)
			while(((_g1 < _g))){
				HX_STACK_LINE(587)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(588)
				::coopy::Unit unit = row_map->get(i);		HX_STACK_VAR(unit,"unit");
				HX_STACK_LINE(589)
				if (((unit == null()))){
					HX_STACK_LINE(589)
					continue;
				}
				HX_STACK_LINE(590)
				output->setCell((int)0,i,this->reportUnit(unit));
			}
		}
		HX_STACK_LINE(592)
		target = Array_obj< int >::__new();
		HX_STACK_LINE(593)
		{
			HX_STACK_LINE(593)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(593)
			int _g = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(593)
			while(((_g1 < _g))){
				HX_STACK_LINE(593)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(594)
				target->push((i + (int)1));
			}
		}
		HX_STACK_LINE(596)
		output->insertOrDeleteRows(target,(output->__Field(HX_CSTRING("get_height"),true)() + (int)1));
		HX_STACK_LINE(597)
		this->l_prev = (int)-1;
		HX_STACK_LINE(598)
		this->r_prev = (int)-1;
		HX_STACK_LINE(599)
		{
			HX_STACK_LINE(599)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(599)
			int _g = output->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(599)
			while(((_g1 < _g))){
				HX_STACK_LINE(599)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(600)
				::coopy::Unit unit = col_map->get((i - (int)1));		HX_STACK_VAR(unit,"unit");
				HX_STACK_LINE(601)
				if (((unit == null()))){
					HX_STACK_LINE(601)
					continue;
				}
				HX_STACK_LINE(602)
				output->setCell(i,(int)0,this->reportUnit(unit));
			}
		}
		HX_STACK_LINE(604)
		output->setCell((int)0,(int)0,HX_CSTRING("@:@"));
	}
	HX_STACK_LINE(607)
	if (((active_column != null()))){
		HX_STACK_LINE(608)
		bool all_active = true;		HX_STACK_VAR(all_active,"all_active");
		HX_STACK_LINE(609)
		{
			HX_STACK_LINE(609)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(609)
			int _g = active_column->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(609)
			while(((_g1 < _g))){
				HX_STACK_LINE(609)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(610)
				if (((active_column->__get(i) == (int)0))){
					HX_STACK_LINE(611)
					all_active = false;
					HX_STACK_LINE(612)
					break;
				}
			}
		}
		HX_STACK_LINE(615)
		if ((!(all_active))){
			HX_STACK_LINE(616)
			Array< int > fate = Array_obj< int >::__new();		HX_STACK_VAR(fate,"fate");
			HX_STACK_LINE(617)
			{
				HX_STACK_LINE(617)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(617)
				while(((_g < admin_w))){
					HX_STACK_LINE(617)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(618)
					fate->push(i);
				}
			}
			HX_STACK_LINE(620)
			int at = admin_w;		HX_STACK_VAR(at,"at");
			HX_STACK_LINE(621)
			int ct = (int)0;		HX_STACK_VAR(ct,"ct");
			HX_STACK_LINE(622)
			Array< int > dots = Array_obj< int >::__new();		HX_STACK_VAR(dots,"dots");
			HX_STACK_LINE(623)
			{
				HX_STACK_LINE(623)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(623)
				int _g = active_column->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(623)
				while(((_g1 < _g))){
					HX_STACK_LINE(623)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(624)
					bool off = (active_column->__get(i) == (int)0);		HX_STACK_VAR(off,"off");
					HX_STACK_LINE(625)
					if ((off)){
						HX_STACK_LINE(625)
						ct = (ct + (int)1);
					}
					else{
						HX_STACK_LINE(625)
						ct = (int)0;
					}
					HX_STACK_LINE(626)
					if (((bool(off) && bool((ct > (int)1))))){
						HX_STACK_LINE(627)
						fate->push((int)-1);
					}
					else{
						HX_STACK_LINE(629)
						if ((off)){
							HX_STACK_LINE(629)
							dots->push(at);
						}
						HX_STACK_LINE(630)
						fate->push(at);
						HX_STACK_LINE(631)
						(at)++;
					}
				}
			}
			HX_STACK_LINE(634)
			output->insertOrDeleteColumns(fate,at);
			HX_STACK_LINE(635)
			{
				HX_STACK_LINE(635)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(635)
				while(((_g < dots->length))){
					HX_STACK_LINE(635)
					int d = dots->__get(_g);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(635)
					++(_g);
					HX_STACK_LINE(636)
					{
						HX_STACK_LINE(636)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(636)
						int _g1 = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(636)
						while(((_g2 < _g1))){
							HX_STACK_LINE(636)
							int j = (_g2)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(637)
							output->setCell(d,j,HX_CSTRING("..."));
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(642)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TableDiff_obj,hilite,return )


TableDiff_obj::TableDiff_obj()
{
}

void TableDiff_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TableDiff);
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_MEMBER_NAME(flags,"flags");
	HX_MARK_MEMBER_NAME(l_prev,"l_prev");
	HX_MARK_MEMBER_NAME(r_prev,"r_prev");
	HX_MARK_END_CLASS();
}

void TableDiff_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(align,"align");
	HX_VISIT_MEMBER_NAME(flags,"flags");
	HX_VISIT_MEMBER_NAME(l_prev,"l_prev");
	HX_VISIT_MEMBER_NAME(r_prev,"r_prev");
}

Dynamic TableDiff_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return align; }
		if (HX_FIELD_EQ(inName,"flags") ) { return flags; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"l_prev") ) { return l_prev; }
		if (HX_FIELD_EQ(inName,"r_prev") ) { return r_prev; }
		if (HX_FIELD_EQ(inName,"hilite") ) { return hilite_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"reportUnit") ) { return reportUnit_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isReordered") ) { return isReordered_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getSeparator") ) { return getSeparator_dyn(); }
		if (HX_FIELD_EQ(inName,"quoteForDiff") ) { return quoteForDiff_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"spreadContext") ) { return spreadContext_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TableDiff_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { align=inValue.Cast< ::coopy::Alignment >(); return inValue; }
		if (HX_FIELD_EQ(inName,"flags") ) { flags=inValue.Cast< ::coopy::CompareFlags >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"l_prev") ) { l_prev=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"r_prev") ) { r_prev=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TableDiff_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("align"));
	outFields->push(HX_CSTRING("flags"));
	outFields->push(HX_CSTRING("l_prev"));
	outFields->push(HX_CSTRING("r_prev"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject,(int)offsetof(TableDiff_obj,align),HX_CSTRING("align")},
	{hx::fsObject,(int)offsetof(TableDiff_obj,flags),HX_CSTRING("flags")},
	{hx::fsObject,(int)offsetof(TableDiff_obj,l_prev),HX_CSTRING("l_prev")},
	{hx::fsObject,(int)offsetof(TableDiff_obj,r_prev),HX_CSTRING("r_prev")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("align"),
	HX_CSTRING("flags"),
	HX_CSTRING("l_prev"),
	HX_CSTRING("r_prev"),
	HX_CSTRING("getSeparator"),
	HX_CSTRING("quoteForDiff"),
	HX_CSTRING("isReordered"),
	HX_CSTRING("spreadContext"),
	HX_CSTRING("reportUnit"),
	HX_CSTRING("hilite"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TableDiff_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TableDiff_obj::__mClass,"__mClass");
};

#endif

Class TableDiff_obj::__mClass;

void TableDiff_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.TableDiff"), hx::TCanCast< TableDiff_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void TableDiff_obj::__boot()
{
}

} // end namespace coopy
