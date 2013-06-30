#include <hxcpp.h>

#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_Change
#include <coopy/Change.h>
#endif
#ifndef INCLUDED_coopy_CompareFlags
#include <coopy/CompareFlags.h>
#endif
#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_Ordering
#include <coopy/Ordering.h>
#endif
#ifndef INCLUDED_coopy_Report
#include <coopy/Report.h>
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
namespace coopy{

Void TableDiff_obj::__construct(::coopy::Alignment align,::coopy::CompareFlags flags)
{
HX_STACK_PUSH("TableDiff::new","coopy/TableDiff.hx",10);
{
	HX_STACK_LINE(11)
	this->align = align;
	HX_STACK_LINE(12)
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

::coopy::Report TableDiff_obj::test( ){
	HX_STACK_PUSH("TableDiff::test","coopy/TableDiff.hx",372);
	HX_STACK_THIS(this);
	HX_STACK_LINE(373)
	::coopy::Report report = ::coopy::Report_obj::__new();		HX_STACK_VAR(report,"report");
	HX_STACK_LINE(374)
	::coopy::Ordering order = this->align->toOrder();		HX_STACK_VAR(order,"order");
	HX_STACK_LINE(375)
	Array< ::coopy::Unit > units = order->getList();		HX_STACK_VAR(units,"units");
	HX_STACK_LINE(376)
	bool has_parent = (this->align->reference != null());		HX_STACK_VAR(has_parent,"has_parent");
	HX_STACK_LINE(377)
	::coopy::Table a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(378)
	::coopy::Table b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(379)
	::coopy::Table p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(380)
	if ((has_parent)){
		HX_STACK_LINE(381)
		p = this->align->getSource();
		HX_STACK_LINE(382)
		a = this->align->reference->getTarget();
		HX_STACK_LINE(383)
		b = this->align->getTarget();
	}
	else{
		HX_STACK_LINE(385)
		a = this->align->getSource();
		HX_STACK_LINE(386)
		b = this->align->getTarget();
		HX_STACK_LINE(387)
		p = a;
	}
	HX_STACK_LINE(390)
	{
		HX_STACK_LINE(390)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = units->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(390)
		while(((_g1 < _g))){
			HX_STACK_LINE(390)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(391)
			::coopy::Unit unit = units->__get(i);		HX_STACK_VAR(unit,"unit");
			HX_STACK_LINE(392)
			if (((bool((bool((unit->p < (int)0)) && bool((unit->l < (int)0)))) && bool((unit->r >= (int)0))))){
				HX_STACK_LINE(392)
				report->changes->push(::coopy::Change_obj::__new((HX_CSTRING("inserted row r:") + unit->r)));
			}
			HX_STACK_LINE(395)
			if (((bool((bool(((bool((unit->p >= (int)0)) || bool(!(has_parent))))) && bool((unit->l >= (int)0)))) && bool((unit->r < (int)0))))){
				HX_STACK_LINE(395)
				report->changes->push(::coopy::Change_obj::__new((HX_CSTRING("deleted row l:") + unit->l)));
			}
			HX_STACK_LINE(398)
			if (((bool((unit->l >= (int)0)) && bool((unit->r >= (int)0))))){
				HX_STACK_LINE(399)
				bool mod = false;		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(400)
				::coopy::View av = a->getCellView();		HX_STACK_VAR(av,"av");
				HX_STACK_LINE(401)
				{
					HX_STACK_LINE(401)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					int _g2 = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(401)
					while(((_g3 < _g2))){
						HX_STACK_LINE(401)
						int j = (_g3)++;		HX_STACK_VAR(j,"j");
					}
				}
			}
		}
	}
	HX_STACK_LINE(407)
	return report;
}


HX_DEFINE_DYNAMIC_FUNC0(TableDiff_obj,test,return )

bool TableDiff_obj::hilite( ::coopy::Table output){
	HX_STACK_PUSH("TableDiff::hilite","coopy/TableDiff.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_ARG(output,"output");
	HX_STACK_LINE(69)
	if ((!(output->isResizable()))){
		HX_STACK_LINE(69)
		return false;
	}
	HX_STACK_LINE(70)
	output->resize((int)0,(int)0);
	HX_STACK_LINE(71)
	output->clear();
	HX_STACK_LINE(73)
	::coopy::Ordering order = this->align->toOrder();		HX_STACK_VAR(order,"order");
	HX_STACK_LINE(74)
	Array< ::coopy::Unit > units = order->getList();		HX_STACK_VAR(units,"units");
	HX_STACK_LINE(75)
	bool has_parent = (this->align->reference != null());		HX_STACK_VAR(has_parent,"has_parent");
	HX_STACK_LINE(76)
	::coopy::Table a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(77)
	::coopy::Table b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(78)
	::coopy::Table p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(79)
	int ra_header = (int)0;		HX_STACK_VAR(ra_header,"ra_header");
	HX_STACK_LINE(80)
	int rb_header = (int)0;		HX_STACK_VAR(rb_header,"rb_header");
	HX_STACK_LINE(81)
	if ((has_parent)){
		HX_STACK_LINE(82)
		p = this->align->getSource();
		HX_STACK_LINE(83)
		a = this->align->reference->getTarget();
		HX_STACK_LINE(84)
		b = this->align->getTarget();
		HX_STACK_LINE(85)
		ra_header = this->align->reference->meta->getTargetHeader();
		HX_STACK_LINE(86)
		rb_header = this->align->meta->getTargetHeader();
	}
	else{
		HX_STACK_LINE(88)
		a = this->align->getSource();
		HX_STACK_LINE(89)
		b = this->align->getTarget();
		HX_STACK_LINE(90)
		p = a;
		HX_STACK_LINE(91)
		ra_header = this->align->meta->getSourceHeader();
		HX_STACK_LINE(92)
		rb_header = this->align->meta->getTargetHeader();
	}
	HX_STACK_LINE(95)
	::coopy::Ordering column_order = this->align->meta->toOrder();		HX_STACK_VAR(column_order,"column_order");
	HX_STACK_LINE(96)
	Array< ::coopy::Unit > column_units = column_order->getList();		HX_STACK_VAR(column_units,"column_units");
	HX_STACK_LINE(98)
	int outer_reps_needed = (  ((this->flags->show_unchanged)) ? int((int)1) : int((int)2) );		HX_STACK_VAR(outer_reps_needed,"outer_reps_needed");
	HX_STACK_LINE(100)
	::coopy::View v = a->getCellView();		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(101)
	::String sep = HX_CSTRING("");		HX_STACK_VAR(sep,"sep");
	HX_STACK_LINE(102)
	::String conflict_sep = HX_CSTRING("");		HX_STACK_VAR(conflict_sep,"conflict_sep");
	HX_STACK_LINE(104)
	Array< ::String > schema = Array_obj< ::String >::__new();		HX_STACK_VAR(schema,"schema");
	HX_STACK_LINE(105)
	bool have_schema = false;		HX_STACK_VAR(have_schema,"have_schema");
	HX_STACK_LINE(106)
	{
		HX_STACK_LINE(106)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(106)
		while(((_g1 < _g))){
			HX_STACK_LINE(106)
			int j = (_g1)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(107)
			::coopy::Unit cunit = column_units->__get(j);		HX_STACK_VAR(cunit,"cunit");
			HX_STACK_LINE(108)
			::String act = HX_CSTRING("");		HX_STACK_VAR(act,"act");
			HX_STACK_LINE(109)
			if (((bool((cunit->r >= (int)0)) && bool((cunit->lp() == (int)-1))))){
				HX_STACK_LINE(110)
				have_schema = true;
				HX_STACK_LINE(111)
				act = HX_CSTRING("+++");
			}
			HX_STACK_LINE(113)
			if (((bool((cunit->r < (int)0)) && bool((cunit->lp() >= (int)0))))){
				HX_STACK_LINE(114)
				have_schema = true;
				HX_STACK_LINE(115)
				act = HX_CSTRING("---");
			}
			HX_STACK_LINE(117)
			if (((bool((cunit->r >= (int)0)) && bool((cunit->lp() >= (int)0))))){
				HX_STACK_LINE(117)
				if (((bool((a->__Field(HX_CSTRING("get_height"),true)() >= ra_header)) && bool((b->__Field(HX_CSTRING("get_height"),true)() >= rb_header))))){
					HX_STACK_LINE(119)
					::coopy::Datum aa = a->getCell(cunit->lp(),ra_header);		HX_STACK_VAR(aa,"aa");
					HX_STACK_LINE(120)
					::coopy::Datum bb = b->getCell(cunit->r,rb_header);		HX_STACK_VAR(bb,"bb");
					HX_STACK_LINE(121)
					if ((!(v->equals(aa,bb)))){
						HX_STACK_LINE(122)
						have_schema = true;
						HX_STACK_LINE(123)
						act = HX_CSTRING("(");
						HX_STACK_LINE(124)
						hx::AddEq(act,v->toString(aa));
						HX_STACK_LINE(125)
						hx::AddEq(act,HX_CSTRING(")"));
					}
				}
			}
			HX_STACK_LINE(129)
			schema->push(act);
		}
	}
	HX_STACK_LINE(131)
	if ((have_schema)){
		HX_STACK_LINE(132)
		int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(133)
		output->resize((column_units->length + (int)1),(at + (int)1));
		HX_STACK_LINE(134)
		output->setCell((int)0,at,v->toDatum(HX_CSTRING("!")));
		HX_STACK_LINE(135)
		{
			HX_STACK_LINE(135)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(135)
			while(((_g1 < _g))){
				HX_STACK_LINE(135)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(136)
				output->setCell((j + (int)1),at,v->toDatum(schema->__get(j)));
			}
		}
	}
	HX_STACK_LINE(140)
	bool top_line_done = false;		HX_STACK_VAR(top_line_done,"top_line_done");
	HX_STACK_LINE(141)
	if ((this->flags->always_show_header)){
		HX_STACK_LINE(142)
		int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(143)
		output->resize((column_units->length + (int)1),(at + (int)1));
		HX_STACK_LINE(144)
		output->setCell((int)0,at,v->toDatum(HX_CSTRING("@@")));
		HX_STACK_LINE(145)
		{
			HX_STACK_LINE(145)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = column_units->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(145)
			while(((_g1 < _g))){
				HX_STACK_LINE(145)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(146)
				::coopy::Unit cunit = column_units->__get(j);		HX_STACK_VAR(cunit,"cunit");
				HX_STACK_LINE(147)
				if (((cunit->r >= (int)0))){
					HX_STACK_LINE(147)
					if (((b->__Field(HX_CSTRING("get_height"),true)() > (int)0))){
						HX_STACK_LINE(148)
						output->setCell((j + (int)1),at,b->getCell(cunit->r,rb_header));
					}
				}
				else{
					HX_STACK_LINE(152)
					if (((cunit->lp() >= (int)0))){
						HX_STACK_LINE(152)
						if (((a->__Field(HX_CSTRING("get_height"),true)() > (int)0))){
							HX_STACK_LINE(153)
							output->setCell((j + (int)1),at,a->getCell(cunit->lp(),ra_header));
						}
					}
				}
			}
		}
		HX_STACK_LINE(159)
		top_line_done = true;
	}
	HX_STACK_LINE(162)
	Array< int > active = Array_obj< int >::__new();		HX_STACK_VAR(active,"active");
	HX_STACK_LINE(163)
	if ((!(this->flags->show_unchanged))){
		HX_STACK_LINE(164)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = units->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(164)
		while(((_g1 < _g))){
			HX_STACK_LINE(164)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(165)
			active[i] = (int)0;
		}
	}
	HX_STACK_LINE(169)
	{
		HX_STACK_LINE(169)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(169)
		while(((_g < outer_reps_needed))){
			HX_STACK_LINE(169)
			int out = (_g)++;		HX_STACK_VAR(out,"out");
			HX_STACK_LINE(170)
			if (((out == (int)1))){
				HX_STACK_LINE(171)
				int del = this->flags->unchanged_context;		HX_STACK_VAR(del,"del");
				HX_STACK_LINE(172)
				if (((del > (int)0))){
					HX_STACK_LINE(174)
					int mark = (-(del) - (int)1);		HX_STACK_VAR(mark,"mark");
					HX_STACK_LINE(175)
					{
						HX_STACK_LINE(175)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						int _g1 = units->length;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(175)
						while(((_g2 < _g1))){
							HX_STACK_LINE(175)
							int i = (_g2)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(176)
							if (((bool((active->__get(i) == (int)0)) || bool((active->__get(i) == (int)3))))){
								HX_STACK_LINE(176)
								if ((((i - mark) <= del))){
									HX_STACK_LINE(177)
									active[i] = (int)2;
								}
								else{
									HX_STACK_LINE(179)
									if ((((i - mark) == (del + (int)1)))){
										HX_STACK_LINE(179)
										active[i] = (int)3;
									}
								}
							}
							else{
								HX_STACK_LINE(182)
								if (((active->__get(i) == (int)1))){
									HX_STACK_LINE(182)
									mark = i;
								}
							}
						}
					}
					HX_STACK_LINE(188)
					mark = ((units->length + del) + (int)1);
					HX_STACK_LINE(189)
					{
						HX_STACK_LINE(189)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						int _g1 = units->length;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(189)
						while(((_g2 < _g1))){
							HX_STACK_LINE(189)
							int j = (_g2)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(190)
							int i = ((units->length - (int)1) - j);		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(191)
							if (((bool((active->__get(i) == (int)0)) || bool((active->__get(i) == (int)3))))){
								HX_STACK_LINE(191)
								if ((((mark - i) <= del))){
									HX_STACK_LINE(192)
									active[i] = (int)2;
								}
								else{
									HX_STACK_LINE(194)
									if ((((mark - i) == (del + (int)1)))){
										HX_STACK_LINE(194)
										active[i] = (int)3;
									}
								}
							}
							else{
								HX_STACK_LINE(197)
								if (((active->__get(i) == (int)1))){
									HX_STACK_LINE(197)
									mark = i;
								}
							}
						}
					}
				}
			}
			HX_STACK_LINE(203)
			bool showed_dummy = false;		HX_STACK_VAR(showed_dummy,"showed_dummy");
			HX_STACK_LINE(204)
			{
				HX_STACK_LINE(204)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				int _g1 = units->length;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(204)
				while(((_g2 < _g1))){
					HX_STACK_LINE(204)
					int i = (_g2)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(205)
					::coopy::Unit unit = units->__get(i);		HX_STACK_VAR(unit,"unit");
					HX_STACK_LINE(207)
					if (((bool((unit->r < (int)0)) && bool((unit->l < (int)0))))){
						HX_STACK_LINE(207)
						continue;
					}
					HX_STACK_LINE(209)
					if (((bool((bool((unit->r == (int)0)) && bool((unit->lp() == (int)0)))) && bool(top_line_done)))){
						HX_STACK_LINE(209)
						continue;
					}
					HX_STACK_LINE(211)
					::String act = HX_CSTRING("");		HX_STACK_VAR(act,"act");
					HX_STACK_LINE(213)
					bool publish = this->flags->show_unchanged;		HX_STACK_VAR(publish,"publish");
					HX_STACK_LINE(214)
					bool dummy = false;		HX_STACK_VAR(dummy,"dummy");
					HX_STACK_LINE(215)
					if (((out == (int)1))){
						HX_STACK_LINE(216)
						publish = (active->__get(i) > (int)0);
						HX_STACK_LINE(217)
						dummy = (active->__get(i) == (int)3);
						HX_STACK_LINE(218)
						if (((bool(dummy) && bool(showed_dummy)))){
							HX_STACK_LINE(218)
							continue;
						}
						HX_STACK_LINE(219)
						if ((!(publish))){
							HX_STACK_LINE(219)
							continue;
						}
					}
					HX_STACK_LINE(222)
					if ((!(dummy))){
						HX_STACK_LINE(222)
						showed_dummy = false;
					}
					HX_STACK_LINE(224)
					int at = output->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(at,"at");
					HX_STACK_LINE(225)
					if ((publish)){
						HX_STACK_LINE(225)
						output->resize((column_units->length + (int)1),(at + (int)1));
					}
					HX_STACK_LINE(229)
					if ((dummy)){
						HX_STACK_LINE(230)
						{
							HX_STACK_LINE(230)
							int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
							int _g3 = (column_units->length + (int)1);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(230)
							while(((_g4 < _g3))){
								HX_STACK_LINE(230)
								int j = (_g4)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(231)
								output->setCell(j,at,v->toDatum(HX_CSTRING("...")));
								HX_STACK_LINE(232)
								showed_dummy = true;
							}
						}
						HX_STACK_LINE(234)
						continue;
					}
					HX_STACK_LINE(237)
					bool have_addition = false;		HX_STACK_VAR(have_addition,"have_addition");
					HX_STACK_LINE(239)
					if (((bool((bool((unit->p < (int)0)) && bool((unit->l < (int)0)))) && bool((unit->r >= (int)0))))){
						HX_STACK_LINE(239)
						act = HX_CSTRING("+++");
					}
					HX_STACK_LINE(242)
					if (((bool((bool(((bool((unit->p >= (int)0)) || bool(!(has_parent))))) && bool((unit->l >= (int)0)))) && bool((unit->r < (int)0))))){
						HX_STACK_LINE(242)
						act = HX_CSTRING("---");
					}
					HX_STACK_LINE(246)
					{
						HX_STACK_LINE(246)
						int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
						int _g3 = column_units->length;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(246)
						while(((_g4 < _g3))){
							HX_STACK_LINE(246)
							int j = (_g4)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(247)
							::coopy::Unit cunit = column_units->__get(j);		HX_STACK_VAR(cunit,"cunit");
							HX_STACK_LINE(248)
							::coopy::Datum pp = null();		HX_STACK_VAR(pp,"pp");
							HX_STACK_LINE(249)
							::coopy::Datum ll = null();		HX_STACK_VAR(ll,"ll");
							HX_STACK_LINE(250)
							::coopy::Datum rr = null();		HX_STACK_VAR(rr,"rr");
							HX_STACK_LINE(251)
							::coopy::Datum dd = null();		HX_STACK_VAR(dd,"dd");
							HX_STACK_LINE(252)
							::coopy::Datum dd_to = null();		HX_STACK_VAR(dd_to,"dd_to");
							HX_STACK_LINE(253)
							bool have_dd_to = false;		HX_STACK_VAR(have_dd_to,"have_dd_to");
							HX_STACK_LINE(254)
							::coopy::Datum dd_to_alt = null();		HX_STACK_VAR(dd_to_alt,"dd_to_alt");
							HX_STACK_LINE(255)
							bool have_dd_to_alt = false;		HX_STACK_VAR(have_dd_to_alt,"have_dd_to_alt");
							HX_STACK_LINE(256)
							bool have_pp = false;		HX_STACK_VAR(have_pp,"have_pp");
							HX_STACK_LINE(257)
							bool have_ll = false;		HX_STACK_VAR(have_ll,"have_ll");
							HX_STACK_LINE(258)
							bool have_rr = false;		HX_STACK_VAR(have_rr,"have_rr");
							HX_STACK_LINE(259)
							if (((bool((cunit->p >= (int)0)) && bool((unit->p >= (int)0))))){
								HX_STACK_LINE(260)
								pp = p->getCell(cunit->p,unit->p);
								HX_STACK_LINE(261)
								have_pp = true;
							}
							HX_STACK_LINE(263)
							if (((bool((cunit->l >= (int)0)) && bool((unit->l >= (int)0))))){
								HX_STACK_LINE(264)
								ll = a->getCell(cunit->l,unit->l);
								HX_STACK_LINE(265)
								have_ll = true;
							}
							HX_STACK_LINE(267)
							if (((bool((cunit->r >= (int)0)) && bool((unit->r >= (int)0))))){
								HX_STACK_LINE(268)
								rr = b->getCell(cunit->r,unit->r);
								HX_STACK_LINE(269)
								have_rr = true;
								HX_STACK_LINE(270)
								if (((((  ((have_pp)) ? int(cunit->p) : int(cunit->l) )) < (int)0))){
									HX_STACK_LINE(270)
									if (((rr != null()))){
										HX_STACK_LINE(271)
										if (((v->toString(rr) != HX_CSTRING("")))){
											HX_STACK_LINE(272)
											have_addition = true;
										}
									}
								}
							}
							HX_STACK_LINE(280)
							if ((have_pp)){
								HX_STACK_LINE(280)
								if ((!(have_rr))){
									HX_STACK_LINE(281)
									dd = pp;
								}
								else{
									HX_STACK_LINE(283)
									if ((v->equals(pp,rr))){
										HX_STACK_LINE(285)
										dd = pp;
									}
									else{
										HX_STACK_LINE(289)
										dd = pp;
										HX_STACK_LINE(290)
										dd_to = rr;
										HX_STACK_LINE(291)
										have_dd_to = true;
										HX_STACK_LINE(293)
										if ((!(v->equals(pp,ll)))){
											HX_STACK_LINE(293)
											if ((!(v->equals(pp,rr)))){
												HX_STACK_LINE(295)
												dd_to_alt = ll;
												HX_STACK_LINE(296)
												have_dd_to_alt = true;
											}
										}
									}
								}
							}
							else{
								HX_STACK_LINE(301)
								if ((have_ll)){
									HX_STACK_LINE(301)
									if ((!(have_rr))){
										HX_STACK_LINE(302)
										dd = ll;
									}
									else{
										HX_STACK_LINE(304)
										if ((v->equals(ll,rr))){
											HX_STACK_LINE(305)
											dd = ll;
										}
										else{
											HX_STACK_LINE(309)
											dd = ll;
											HX_STACK_LINE(310)
											dd_to = rr;
											HX_STACK_LINE(311)
											have_dd_to = true;
										}
									}
								}
								else{
									HX_STACK_LINE(314)
									dd = rr;
								}
							}
							HX_STACK_LINE(318)
							::String txt = null();		HX_STACK_VAR(txt,"txt");
							HX_STACK_LINE(319)
							if ((have_dd_to)){
								HX_STACK_LINE(320)
								txt = this->quoteForDiff(v,dd);
								HX_STACK_LINE(322)
								if (((sep == HX_CSTRING("")))){
									HX_STACK_LINE(322)
									sep = this->getSeparator(a,null(),HX_CSTRING("->"));
								}
								HX_STACK_LINE(325)
								bool is_conflict = false;		HX_STACK_VAR(is_conflict,"is_conflict");
								HX_STACK_LINE(326)
								if ((have_dd_to_alt)){
									HX_STACK_LINE(326)
									if ((!(v->equals(dd_to,dd_to_alt)))){
										HX_STACK_LINE(327)
										is_conflict = true;
									}
								}
								HX_STACK_LINE(331)
								if ((!(is_conflict))){
									HX_STACK_LINE(332)
									txt = ((txt + sep) + this->quoteForDiff(v,dd_to));
									HX_STACK_LINE(333)
									if (((sep.length > act.length))){
										HX_STACK_LINE(333)
										act = sep;
									}
								}
								else{
									HX_STACK_LINE(337)
									if (((conflict_sep == HX_CSTRING("")))){
										HX_STACK_LINE(337)
										conflict_sep = (this->getSeparator(p,a,HX_CSTRING("!")) + sep);
									}
									HX_STACK_LINE(340)
									txt = ((((txt + conflict_sep) + this->quoteForDiff(v,dd_to_alt)) + conflict_sep) + this->quoteForDiff(v,dd_to));
									HX_STACK_LINE(343)
									act = conflict_sep;
								}
							}
							HX_STACK_LINE(346)
							if (((bool((act == HX_CSTRING(""))) && bool(have_addition)))){
								HX_STACK_LINE(346)
								act = HX_CSTRING("+");
							}
							HX_STACK_LINE(349)
							if ((publish)){
								HX_STACK_LINE(349)
								if (((txt != null()))){
									HX_STACK_LINE(350)
									output->setCell((j + (int)1),at,v->toDatum(txt));
								}
								else{
									HX_STACK_LINE(352)
									output->setCell((j + (int)1),at,dd);
								}
							}
						}
					}
					HX_STACK_LINE(358)
					if ((publish)){
						HX_STACK_LINE(358)
						output->setCell((int)0,at,v->toDatum(act));
					}
					HX_STACK_LINE(359)
					if (((act != HX_CSTRING("")))){
						HX_STACK_LINE(359)
						if ((!(publish))){
							HX_STACK_LINE(360)
							if (((active != null()))){
								HX_STACK_LINE(361)
								active[i] = (int)1;
							}
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(368)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TableDiff_obj,hilite,return )

::String TableDiff_obj::quoteForDiff( ::coopy::View v,::coopy::Datum d){
	HX_STACK_PUSH("TableDiff::quoteForDiff","coopy/TableDiff.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(47)
	::String nil = HX_CSTRING("NULL");		HX_STACK_VAR(nil,"nil");
	HX_STACK_LINE(48)
	if ((v->equals(d,null()))){
		HX_STACK_LINE(48)
		return nil;
	}
	HX_STACK_LINE(51)
	::String str = v->toString(d);		HX_STACK_VAR(str,"str");
	HX_STACK_LINE(52)
	int score = (int)0;		HX_STACK_VAR(score,"score");
	HX_STACK_LINE(53)
	{
		HX_STACK_LINE(53)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = str.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(53)
		while(((_g1 < _g))){
			HX_STACK_LINE(53)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(54)
			if (((str.charCodeAt(score) != (int)95))){
				HX_STACK_LINE(54)
				break;
			}
			HX_STACK_LINE(55)
			(score)++;
		}
	}
	HX_STACK_LINE(62)
	if (((str.substr(score,null()) == nil))){
		HX_STACK_LINE(62)
		str = (HX_CSTRING("_") + str);
	}
	HX_STACK_LINE(65)
	return str;
}


HX_DEFINE_DYNAMIC_FUNC2(TableDiff_obj,quoteForDiff,return )

::String TableDiff_obj::getSeparator( ::coopy::Table t,::coopy::Table t2,::String root){
	HX_STACK_PUSH("TableDiff::getSeparator","coopy/TableDiff.hx",17);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(t2,"t2");
	HX_STACK_ARG(root,"root");
	HX_STACK_LINE(18)
	::String sep = root;		HX_STACK_VAR(sep,"sep");
	HX_STACK_LINE(19)
	int w = t->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(20)
	int h = t->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(21)
	::coopy::View view = t->getCellView();		HX_STACK_VAR(view,"view");
	HX_STACK_LINE(22)
	{
		HX_STACK_LINE(22)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(22)
		while(((_g < h))){
			HX_STACK_LINE(22)
			int y = (_g)++;		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(23)
			{
				HX_STACK_LINE(23)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(23)
				while(((_g1 < w))){
					HX_STACK_LINE(23)
					int x = (_g1)++;		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(24)
					::String txt = view->toString(t->getCell(x,y));		HX_STACK_VAR(txt,"txt");
					HX_STACK_LINE(25)
					if (((txt == null()))){
						HX_STACK_LINE(25)
						continue;
					}
					HX_STACK_LINE(26)
					while(((txt.indexOf(sep,null()) >= (int)0))){
						HX_STACK_LINE(26)
						sep = (HX_CSTRING("-") + sep);
					}
				}
			}
		}
	}
	HX_STACK_LINE(31)
	if (((t2 != null()))){
		HX_STACK_LINE(32)
		w = t2->__Field(HX_CSTRING("get_width"),true)();
		HX_STACK_LINE(33)
		h = t2->__Field(HX_CSTRING("get_height"),true)();
		HX_STACK_LINE(34)
		{
			HX_STACK_LINE(34)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(34)
			while(((_g < h))){
				HX_STACK_LINE(34)
				int y = (_g)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(35)
				{
					HX_STACK_LINE(35)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(35)
					while(((_g1 < w))){
						HX_STACK_LINE(35)
						int x = (_g1)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(36)
						::String txt = view->toString(t2->getCell(x,y));		HX_STACK_VAR(txt,"txt");
						HX_STACK_LINE(37)
						while(((txt.indexOf(sep,null()) >= (int)0))){
							HX_STACK_LINE(37)
							sep = (HX_CSTRING("-") + sep);
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(43)
	return sep;
}


HX_DEFINE_DYNAMIC_FUNC3(TableDiff_obj,getSeparator,return )


TableDiff_obj::TableDiff_obj()
{
}

void TableDiff_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TableDiff);
	HX_MARK_MEMBER_NAME(flags,"flags");
	HX_MARK_MEMBER_NAME(align,"align");
	HX_MARK_END_CLASS();
}

void TableDiff_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(flags,"flags");
	HX_VISIT_MEMBER_NAME(align,"align");
}

Dynamic TableDiff_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"test") ) { return test_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flags") ) { return flags; }
		if (HX_FIELD_EQ(inName,"align") ) { return align; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"hilite") ) { return hilite_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"quoteForDiff") ) { return quoteForDiff_dyn(); }
		if (HX_FIELD_EQ(inName,"getSeparator") ) { return getSeparator_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TableDiff_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"flags") ) { flags=inValue.Cast< ::coopy::CompareFlags >(); return inValue; }
		if (HX_FIELD_EQ(inName,"align") ) { align=inValue.Cast< ::coopy::Alignment >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TableDiff_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("flags"));
	outFields->push(HX_CSTRING("align"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("test"),
	HX_CSTRING("hilite"),
	HX_CSTRING("quoteForDiff"),
	HX_CSTRING("getSeparator"),
	HX_CSTRING("flags"),
	HX_CSTRING("align"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TableDiff_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TableDiff_obj::__mClass,"__mClass");
};

Class TableDiff_obj::__mClass;

void TableDiff_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.TableDiff"), hx::TCanCast< TableDiff_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TableDiff_obj::__boot()
{
}

} // end namespace coopy
