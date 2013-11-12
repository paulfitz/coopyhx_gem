#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_CompareTable
#include <coopy/CompareTable.h>
#endif
#ifndef INCLUDED_coopy_CrossMatch
#include <coopy/CrossMatch.h>
#endif
#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
#ifndef INCLUDED_coopy_IndexPair
#include <coopy/IndexPair.h>
#endif
#ifndef INCLUDED_coopy_Ordering
#include <coopy/Ordering.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_TableComparisonState
#include <coopy/TableComparisonState.h>
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
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace coopy{

Void CompareTable_obj::__construct()
{
HX_STACK_FRAME("coopy.CompareTable","new",0x57f8745d,"coopy.CompareTable.new","coopy/CompareTable.hx",10,0x02212ed2)
{
}
;
	return null();
}

CompareTable_obj::~CompareTable_obj() { }

Dynamic CompareTable_obj::__CreateEmpty() { return  new CompareTable_obj; }
hx::ObjectPtr< CompareTable_obj > CompareTable_obj::__new()
{  hx::ObjectPtr< CompareTable_obj > result = new CompareTable_obj();
	result->__construct();
	return result;}

Dynamic CompareTable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CompareTable_obj > result = new CompareTable_obj();
	result->__construct();
	return result;}

bool CompareTable_obj::attach( ::coopy::TableComparisonState comp){
	HX_STACK_FRAME("coopy.CompareTable","attach",0x4bee33e8,"coopy.CompareTable.attach","coopy/CompareTable.hx",12,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(comp,"comp")
	HX_STACK_LINE(13)
	this->comp = comp;
	HX_STACK_LINE(14)
	bool more = this->compareCore();		HX_STACK_VAR(more,"more");
	HX_STACK_LINE(15)
	while(((bool(more) && bool(comp->run_to_completion)))){
		HX_STACK_LINE(16)
		more = this->compareCore();
	}
	HX_STACK_LINE(18)
	return !(more);
}


HX_DEFINE_DYNAMIC_FUNC1(CompareTable_obj,attach,return )

::coopy::Alignment CompareTable_obj::align( ){
	HX_STACK_FRAME("coopy.CompareTable","align",0x26a4b402,"coopy.CompareTable.align","coopy/CompareTable.hx",21,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(22)
	::coopy::Alignment alignment = ::coopy::Alignment_obj::__new();		HX_STACK_VAR(alignment,"alignment");
	HX_STACK_LINE(23)
	this->alignCore(alignment);
	HX_STACK_LINE(24)
	return alignment;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,align,return )

::coopy::TableComparisonState CompareTable_obj::getComparisonState( ){
	HX_STACK_FRAME("coopy.CompareTable","getComparisonState",0x5bfac2b5,"coopy.CompareTable.getComparisonState","coopy/CompareTable.hx",28,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(28)
	return this->comp;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,getComparisonState,return )

Void CompareTable_obj::alignCore( ::coopy::Alignment align){
{
		HX_STACK_FRAME("coopy.CompareTable","alignCore",0xbc79c681,"coopy.CompareTable.alignCore","coopy/CompareTable.hx",31,0x02212ed2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(align,"align")
		HX_STACK_LINE(32)
		if (((this->comp->p == null()))){
			HX_STACK_LINE(33)
			this->alignCore2(align,this->comp->a,this->comp->b);
			HX_STACK_LINE(34)
			return null();
		}
		HX_STACK_LINE(36)
		align->reference = ::coopy::Alignment_obj::__new();
		HX_STACK_LINE(37)
		this->alignCore2(align,this->comp->p,this->comp->b);
		HX_STACK_LINE(38)
		this->alignCore2(align->reference,this->comp->p,this->comp->a);
		HX_STACK_LINE(39)
		align->meta->reference = align->reference->meta;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CompareTable_obj,alignCore,(void))

Void CompareTable_obj::alignCore2( ::coopy::Alignment align,::coopy::Table a,::coopy::Table b){
{
		HX_STACK_FRAME("coopy.CompareTable","alignCore2",0x2e13ea91,"coopy.CompareTable.alignCore2","coopy/CompareTable.hx",44,0x02212ed2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(align,"align")
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(45)
		if (((align->meta == null()))){
			HX_STACK_LINE(46)
			align->meta = ::coopy::Alignment_obj::__new();
		}
		HX_STACK_LINE(48)
		this->alignColumns(align->meta,a,b);
		HX_STACK_LINE(49)
		::coopy::Ordering column_order = align->meta->toOrder();		HX_STACK_VAR(column_order,"column_order");
		HX_STACK_LINE(50)
		Array< ::Dynamic > common_units = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(common_units,"common_units");
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(51)
			Array< ::Dynamic > _g1 = column_order->getList();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(51)
			while(((_g < _g1->length))){
				HX_STACK_LINE(51)
				::coopy::Unit unit = _g1->__get(_g).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(unit,"unit");
				HX_STACK_LINE(51)
				++(_g);
				HX_STACK_LINE(52)
				if (((bool((bool((unit->l >= (int)0)) && bool((unit->r >= (int)0)))) && bool((unit->p != (int)-1))))){
					HX_STACK_LINE(53)
					common_units->push(unit);
				}
			}
		}
		HX_STACK_LINE(57)
		int _g = a->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		align->range(_g,b->__Field(HX_CSTRING("get_height"),true)());
		HX_STACK_LINE(58)
		align->tables(a,b);
		HX_STACK_LINE(59)
		align->setRowlike(true);
		HX_STACK_LINE(61)
		int w = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(62)
		int ha = a->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(ha,"ha");
		HX_STACK_LINE(63)
		int hb = b->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(hb,"hb");
		HX_STACK_LINE(65)
		::coopy::View av = a->getCellView();		HX_STACK_VAR(av,"av");
		HX_STACK_LINE(70)
		int N = (int)5;		HX_STACK_VAR(N,"N");
		HX_STACK_LINE(71)
		Array< int > columns = Array_obj< int >::__new();		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(72)
		if (((common_units->length > N))){
			HX_STACK_LINE(73)
			Array< ::Dynamic > columns_eval = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(columns_eval,"columns_eval");
			HX_STACK_LINE(74)
			{
				HX_STACK_LINE(74)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(74)
				int _g2 = common_units->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(74)
				while(((_g1 < _g2))){
					HX_STACK_LINE(74)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(75)
					int ct = (int)0;		HX_STACK_VAR(ct,"ct");
					HX_STACK_LINE(76)
					::haxe::ds::StringMap mem = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(mem,"mem");
					HX_STACK_LINE(77)
					::haxe::ds::StringMap mem2 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(mem2,"mem2");
					HX_STACK_LINE(78)
					int ca = common_units->__get(i).StaticCast< ::coopy::Unit >()->l;		HX_STACK_VAR(ca,"ca");
					HX_STACK_LINE(79)
					int cb = common_units->__get(i).StaticCast< ::coopy::Unit >()->r;		HX_STACK_VAR(cb,"cb");
					HX_STACK_LINE(80)
					{
						HX_STACK_LINE(80)
						int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(80)
						while(((_g21 < ha))){
							HX_STACK_LINE(80)
							int j = (_g21)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(81)
							::String key = av->toString(a->getCell(ca,j));		HX_STACK_VAR(key,"key");
							HX_STACK_LINE(82)
							if ((!(mem->exists(key)))){
								HX_STACK_LINE(83)
								mem->set(key,(int)1);
								HX_STACK_LINE(84)
								(ct)++;
							}
						}
					}
					HX_STACK_LINE(87)
					{
						HX_STACK_LINE(87)
						int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(87)
						while(((_g21 < hb))){
							HX_STACK_LINE(87)
							int j = (_g21)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(88)
							::String key = av->toString(b->getCell(cb,j));		HX_STACK_VAR(key,"key");
							HX_STACK_LINE(89)
							if ((!(mem2->exists(key)))){
								HX_STACK_LINE(90)
								mem2->set(key,(int)1);
								HX_STACK_LINE(91)
								(ct)++;
							}
						}
					}
					HX_STACK_LINE(94)
					columns_eval->push(Array_obj< int >::__new().Add(i).Add(ct));
				}
			}

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			int run(Array< int > a1,Array< int > b1){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","coopy/CompareTable.hx",96,0x02212ed2)
				HX_STACK_ARG(a1,"a1")
				HX_STACK_ARG(b1,"b1")
				{
					HX_STACK_LINE(96)
					if (((a1->__get((int)1) < b1->__get((int)1)))){
						HX_STACK_LINE(96)
						return (int)1;
					}
					HX_STACK_LINE(96)
					if (((a1->__get((int)1) > b1->__get((int)1)))){
						HX_STACK_LINE(96)
						return (int)-1;
					}
					HX_STACK_LINE(96)
					return (int)0;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(96)
			Dynamic sorter =  Dynamic(new _Function_2_1());		HX_STACK_VAR(sorter,"sorter");
			HX_STACK_LINE(97)
			columns_eval->sort(sorter);

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_2)
			int run(Array< int > v){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","coopy/CompareTable.hx",98,0x02212ed2)
				HX_STACK_ARG(v,"v")
				{
					HX_STACK_LINE(98)
					return v->__get((int)0);
				}
				return null();
			}
			HX_END_LOCAL_FUNC1(return)

			HX_STACK_LINE(98)
			columns = ::Lambda_obj::array(::Lambda_obj::map(columns_eval, Dynamic(new _Function_2_2())));
			HX_STACK_LINE(99)
			columns = columns->slice((int)0,N);
		}
		else{
			HX_STACK_LINE(101)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(101)
			int _g2 = common_units->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(101)
			while(((_g1 < _g2))){
				HX_STACK_LINE(101)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(102)
				columns->push(i);
			}
		}
		HX_STACK_LINE(106)
		int top = ::Math_obj::round(::Math_obj::pow((int)2,columns->length));		HX_STACK_VAR(top,"top");
		HX_STACK_LINE(108)
		::haxe::ds::IntMap pending = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(pending,"pending");
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(109)
			while(((_g1 < ha))){
				HX_STACK_LINE(109)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(110)
				pending->set(j,j);
			}
		}
		HX_STACK_LINE(112)
		int pending_ct = ha;		HX_STACK_VAR(pending_ct,"pending_ct");
		HX_STACK_LINE(114)
		{
			HX_STACK_LINE(114)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(114)
			while(((_g1 < top))){
				HX_STACK_LINE(114)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(115)
				if (((k == (int)0))){
					HX_STACK_LINE(115)
					continue;
				}
				HX_STACK_LINE(116)
				if (((pending_ct == (int)0))){
					HX_STACK_LINE(116)
					break;
				}
				HX_STACK_LINE(117)
				Array< int > active_columns = Array_obj< int >::__new();		HX_STACK_VAR(active_columns,"active_columns");
				HX_STACK_LINE(118)
				int kk = k;		HX_STACK_VAR(kk,"kk");
				HX_STACK_LINE(119)
				int at = (int)0;		HX_STACK_VAR(at,"at");
				HX_STACK_LINE(120)
				while(((kk > (int)0))){
					HX_STACK_LINE(121)
					if (((hx::Mod(kk,(int)2) == (int)1))){
						HX_STACK_LINE(122)
						active_columns->push(columns->__get(at));
					}
					HX_STACK_LINE(124)
					hx::ShrEq(kk,(int)1);
					HX_STACK_LINE(125)
					(at)++;
				}
				HX_STACK_LINE(128)
				::coopy::IndexPair index = ::coopy::IndexPair_obj::__new();		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(129)
				{
					HX_STACK_LINE(129)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(129)
					int _g11 = active_columns->length;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(129)
					while(((_g2 < _g11))){
						HX_STACK_LINE(129)
						int k1 = (_g2)++;		HX_STACK_VAR(k1,"k1");
						HX_STACK_LINE(130)
						::coopy::Unit unit = common_units->__get(active_columns->__get(k1)).StaticCast< ::coopy::Unit >();		HX_STACK_VAR(unit,"unit");
						HX_STACK_LINE(131)
						index->addColumns(unit->l,unit->r);
						HX_STACK_LINE(132)
						align->addIndexColumns(unit);
					}
				}
				HX_STACK_LINE(134)
				index->indexTables(a,b);
				HX_STACK_LINE(136)
				int h = a->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(h,"h");
				HX_STACK_LINE(137)
				if (((b->__Field(HX_CSTRING("get_height"),true)() > h))){
					HX_STACK_LINE(137)
					h = b->__Field(HX_CSTRING("get_height"),true)();
				}
				HX_STACK_LINE(138)
				if (((h < (int)1))){
					HX_STACK_LINE(138)
					h = (int)1;
				}
				HX_STACK_LINE(139)
				int wide_top_freq = index->getTopFreq();		HX_STACK_VAR(wide_top_freq,"wide_top_freq");
				HX_STACK_LINE(140)
				Float ratio = wide_top_freq;		HX_STACK_VAR(ratio,"ratio");
				HX_STACK_LINE(141)
				hx::DivEq(ratio,(h + (int)20));
				HX_STACK_LINE(142)
				if (((ratio >= 0.1))){
					HX_STACK_LINE(142)
					continue;
				}
				HX_STACK_LINE(144)
				if (((this->indexes != null()))){
					HX_STACK_LINE(145)
					this->indexes->push(index);
				}
				HX_STACK_LINE(148)
				Array< int > fixed = Array_obj< int >::__new();		HX_STACK_VAR(fixed,"fixed");
				HX_STACK_LINE(149)
				for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(pending->keys());  __it->hasNext(); ){
					int j = __it->next();
					{
						HX_STACK_LINE(150)
						::coopy::CrossMatch cross = index->queryLocal(j);		HX_STACK_VAR(cross,"cross");
						HX_STACK_LINE(151)
						int spot_a = cross->spot_a;		HX_STACK_VAR(spot_a,"spot_a");
						HX_STACK_LINE(152)
						int spot_b = cross->spot_b;		HX_STACK_VAR(spot_b,"spot_b");
						HX_STACK_LINE(153)
						if (((bool((spot_a != (int)1)) || bool((spot_b != (int)1))))){
							HX_STACK_LINE(153)
							continue;
						}
						HX_STACK_LINE(154)
						fixed->push(j);
						HX_STACK_LINE(155)
						align->link(j,cross->item_b->lst->__get((int)0));
					}
;
				}
				HX_STACK_LINE(157)
				{
					HX_STACK_LINE(157)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(157)
					int _g11 = fixed->length;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(157)
					while(((_g2 < _g11))){
						HX_STACK_LINE(157)
						int j = (_g2)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(158)
						pending->remove(fixed->__get(j));
						HX_STACK_LINE(159)
						(pending_ct)--;
					}
				}
			}
		}
		HX_STACK_LINE(163)
		align->link((int)0,(int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CompareTable_obj,alignCore2,(void))

Void CompareTable_obj::alignColumns( ::coopy::Alignment align,::coopy::Table a,::coopy::Table b){
{
		HX_STACK_FRAME("coopy.CompareTable","alignColumns",0x612984fb,"coopy.CompareTable.alignColumns","coopy/CompareTable.hx",166,0x02212ed2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(align,"align")
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(167)
		int _g1 = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(167)
		align->range(_g1,b->__Field(HX_CSTRING("get_width"),true)());
		HX_STACK_LINE(168)
		align->tables(a,b);
		HX_STACK_LINE(169)
		align->setRowlike(false);
		HX_STACK_LINE(171)
		int slop = (int)5;		HX_STACK_VAR(slop,"slop");
		HX_STACK_LINE(173)
		::coopy::View va = a->getCellView();		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(174)
		::coopy::View vb = b->getCellView();		HX_STACK_VAR(vb,"vb");
		HX_STACK_LINE(175)
		int ra_best = (int)0;		HX_STACK_VAR(ra_best,"ra_best");
		HX_STACK_LINE(176)
		int rb_best = (int)0;		HX_STACK_VAR(rb_best,"rb_best");
		HX_STACK_LINE(177)
		int ct_best = (int)-1;		HX_STACK_VAR(ct_best,"ct_best");
		HX_STACK_LINE(178)
		::haxe::ds::StringMap ma_best = null();		HX_STACK_VAR(ma_best,"ma_best");
		HX_STACK_LINE(179)
		::haxe::ds::StringMap mb_best = null();		HX_STACK_VAR(mb_best,"mb_best");
		HX_STACK_LINE(180)
		int ra_header = (int)0;		HX_STACK_VAR(ra_header,"ra_header");
		HX_STACK_LINE(181)
		int rb_header = (int)0;		HX_STACK_VAR(rb_header,"rb_header");
		HX_STACK_LINE(182)
		int ra_uniques = (int)0;		HX_STACK_VAR(ra_uniques,"ra_uniques");
		HX_STACK_LINE(183)
		int rb_uniques = (int)0;		HX_STACK_VAR(rb_uniques,"rb_uniques");
		HX_STACK_LINE(184)
		{
			HX_STACK_LINE(184)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(184)
			while(((_g < slop))){
				HX_STACK_LINE(184)
				int ra = (_g)++;		HX_STACK_VAR(ra,"ra");
				HX_STACK_LINE(185)
				if (((ra >= a->__Field(HX_CSTRING("get_height"),true)()))){
					HX_STACK_LINE(185)
					break;
				}
				HX_STACK_LINE(186)
				{
					HX_STACK_LINE(186)
					int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(186)
					while(((_g11 < slop))){
						HX_STACK_LINE(186)
						int rb = (_g11)++;		HX_STACK_VAR(rb,"rb");
						HX_STACK_LINE(187)
						if (((rb >= b->__Field(HX_CSTRING("get_height"),true)()))){
							HX_STACK_LINE(187)
							break;
						}
						HX_STACK_LINE(188)
						::haxe::ds::StringMap ma = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(ma,"ma");
						HX_STACK_LINE(189)
						::haxe::ds::StringMap mb = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(mb,"mb");
						HX_STACK_LINE(190)
						int ct = (int)0;		HX_STACK_VAR(ct,"ct");
						HX_STACK_LINE(191)
						int uniques = (int)0;		HX_STACK_VAR(uniques,"uniques");
						HX_STACK_LINE(192)
						{
							HX_STACK_LINE(192)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(192)
							int _g2 = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(192)
							while(((_g3 < _g2))){
								HX_STACK_LINE(192)
								int ca = (_g3)++;		HX_STACK_VAR(ca,"ca");
								HX_STACK_LINE(193)
								::String key = va->toString(a->getCell(ca,ra));		HX_STACK_VAR(key,"key");
								HX_STACK_LINE(194)
								if ((ma->exists(key))){
									HX_STACK_LINE(195)
									ma->set(key,(int)-1);
									HX_STACK_LINE(196)
									(uniques)--;
								}
								else{
									HX_STACK_LINE(198)
									ma->set(key,ca);
									HX_STACK_LINE(199)
									(uniques)++;
								}
							}
						}
						HX_STACK_LINE(202)
						if (((uniques > ra_uniques))){
							HX_STACK_LINE(203)
							ra_header = ra;
							HX_STACK_LINE(204)
							ra_uniques = uniques;
						}
						HX_STACK_LINE(206)
						uniques = (int)0;
						HX_STACK_LINE(207)
						{
							HX_STACK_LINE(207)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(207)
							int _g2 = b->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(207)
							while(((_g3 < _g2))){
								HX_STACK_LINE(207)
								int cb = (_g3)++;		HX_STACK_VAR(cb,"cb");
								HX_STACK_LINE(208)
								::String key = vb->toString(b->getCell(cb,rb));		HX_STACK_VAR(key,"key");
								HX_STACK_LINE(209)
								if ((mb->exists(key))){
									HX_STACK_LINE(210)
									mb->set(key,(int)-1);
									HX_STACK_LINE(211)
									(uniques)--;
								}
								else{
									HX_STACK_LINE(213)
									mb->set(key,cb);
									HX_STACK_LINE(214)
									(uniques)++;
								}
							}
						}
						HX_STACK_LINE(217)
						if (((uniques > rb_uniques))){
							HX_STACK_LINE(218)
							rb_header = rb;
							HX_STACK_LINE(219)
							rb_uniques = uniques;
						}
						HX_STACK_LINE(222)
						for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(ma->keys());  __it->hasNext(); ){
							::String key = __it->next();
							{
								HX_STACK_LINE(223)
								int i0 = ma->get(key);		HX_STACK_VAR(i0,"i0");
								HX_STACK_LINE(224)
								Dynamic i1 = mb->get(key);		HX_STACK_VAR(i1,"i1");
								HX_STACK_LINE(225)
								if (((bool((i1 >= (int)0)) && bool((i0 >= (int)0))))){
									HX_STACK_LINE(226)
									(ct)++;
								}
							}
;
						}
						HX_STACK_LINE(230)
						if (((ct > ct_best))){
							HX_STACK_LINE(231)
							ct_best = ct;
							HX_STACK_LINE(232)
							ma_best = ma;
							HX_STACK_LINE(233)
							mb_best = mb;
							HX_STACK_LINE(234)
							ra_best = ra;
							HX_STACK_LINE(235)
							rb_best = rb;
						}
					}
				}
			}
		}
		HX_STACK_LINE(240)
		if (((ma_best == null()))){
			HX_STACK_LINE(240)
			return null();
		}
		HX_STACK_LINE(241)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(ma_best->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(242)
				int i0 = ma_best->get(key);		HX_STACK_VAR(i0,"i0");
				HX_STACK_LINE(243)
				Dynamic i1 = mb_best->get(key);		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(244)
				if (((bool((i1 >= (int)0)) && bool((i0 >= (int)0))))){
					HX_STACK_LINE(245)
					align->link(i0,i1);
				}
			}
;
		}
		HX_STACK_LINE(248)
		align->headers(ra_header,rb_header);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CompareTable_obj,alignColumns,(void))

bool CompareTable_obj::testHasSameColumns( ){
	HX_STACK_FRAME("coopy.CompareTable","testHasSameColumns",0xe0215572,"coopy.CompareTable.testHasSameColumns","coopy/CompareTable.hx",251,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(252)
	::coopy::Table p = this->comp->p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(253)
	::coopy::Table a = this->comp->a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(254)
	::coopy::Table b = this->comp->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(255)
	bool eq = this->hasSameColumns2(a,b);		HX_STACK_VAR(eq,"eq");
	HX_STACK_LINE(256)
	if (((bool(eq) && bool((p != null()))))){
		HX_STACK_LINE(257)
		eq = this->hasSameColumns2(p,a);
	}
	HX_STACK_LINE(259)
	this->comp->has_same_columns = eq;
	HX_STACK_LINE(260)
	this->comp->has_same_columns_known = true;
	HX_STACK_LINE(261)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,testHasSameColumns,return )

bool CompareTable_obj::hasSameColumns2( ::coopy::Table a,::coopy::Table b){
	HX_STACK_FRAME("coopy.CompareTable","hasSameColumns2",0x6f410032,"coopy.CompareTable.hasSameColumns2","coopy/CompareTable.hx",264,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(265)
	if (((a->__Field(HX_CSTRING("get_width"),true)() != b->__Field(HX_CSTRING("get_width"),true)()))){
		HX_STACK_LINE(266)
		return false;
	}
	HX_STACK_LINE(268)
	if (((bool((a->__Field(HX_CSTRING("get_height"),true)() == (int)0)) || bool((b->__Field(HX_CSTRING("get_height"),true)() == (int)0))))){
		HX_STACK_LINE(269)
		return true;
	}
	HX_STACK_LINE(274)
	::coopy::View av = a->getCellView();		HX_STACK_VAR(av,"av");
	HX_STACK_LINE(275)
	{
		HX_STACK_LINE(275)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(275)
		int _g = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(275)
		while(((_g1 < _g))){
			HX_STACK_LINE(275)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(276)
			{
				HX_STACK_LINE(276)
				int _g3 = (i + (int)1);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(276)
				int _g2 = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(276)
				while(((_g3 < _g2))){
					HX_STACK_LINE(276)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(277)
					Dynamic _g21 = a->getCell(i,(int)0);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(277)
					if ((av->equals(_g21,a->getCell(j,(int)0)))){
						HX_STACK_LINE(278)
						return false;
					}
				}
			}
			HX_STACK_LINE(281)
			Dynamic _g3 = a->getCell(i,(int)0);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(281)
			if ((!(av->equals(_g3,b->getCell(i,(int)0))))){
				HX_STACK_LINE(282)
				return false;
			}
		}
	}
	HX_STACK_LINE(286)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(CompareTable_obj,hasSameColumns2,return )

bool CompareTable_obj::testIsEqual( ){
	HX_STACK_FRAME("coopy.CompareTable","testIsEqual",0x95e5ca35,"coopy.CompareTable.testIsEqual","coopy/CompareTable.hx",289,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(290)
	::coopy::Table p = this->comp->p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(291)
	::coopy::Table a = this->comp->a;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(292)
	::coopy::Table b = this->comp->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(293)
	bool eq = this->isEqual2(a,b);		HX_STACK_VAR(eq,"eq");
	HX_STACK_LINE(294)
	if (((bool(eq) && bool((p != null()))))){
		HX_STACK_LINE(295)
		eq = this->isEqual2(p,a);
	}
	HX_STACK_LINE(297)
	this->comp->is_equal = eq;
	HX_STACK_LINE(298)
	this->comp->is_equal_known = true;
	HX_STACK_LINE(299)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,testIsEqual,return )

bool CompareTable_obj::isEqual2( ::coopy::Table a,::coopy::Table b){
	HX_STACK_FRAME("coopy.CompareTable","isEqual2",0xe253506b,"coopy.CompareTable.isEqual2","coopy/CompareTable.hx",302,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(303)
	if (((bool((a->__Field(HX_CSTRING("get_width"),true)() != b->__Field(HX_CSTRING("get_width"),true)())) || bool((a->__Field(HX_CSTRING("get_height"),true)() != b->__Field(HX_CSTRING("get_height"),true)()))))){
		HX_STACK_LINE(304)
		return false;
	}
	HX_STACK_LINE(306)
	::coopy::View av = a->getCellView();		HX_STACK_VAR(av,"av");
	HX_STACK_LINE(307)
	{
		HX_STACK_LINE(307)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(307)
		int _g = a->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(307)
		while(((_g1 < _g))){
			HX_STACK_LINE(307)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(308)
			{
				HX_STACK_LINE(308)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(308)
				int _g2 = a->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(308)
				while(((_g3 < _g2))){
					HX_STACK_LINE(308)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(309)
					Dynamic _g4 = a->getCell(j,i);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(309)
					if ((!(av->equals(_g4,b->getCell(j,i))))){
						HX_STACK_LINE(310)
						return false;
					}
				}
			}
		}
	}
	HX_STACK_LINE(314)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(CompareTable_obj,isEqual2,return )

bool CompareTable_obj::compareCore( ){
	HX_STACK_FRAME("coopy.CompareTable","compareCore",0x81a521a1,"coopy.CompareTable.compareCore","coopy/CompareTable.hx",317,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(318)
	if ((this->comp->completed)){
		HX_STACK_LINE(318)
		return false;
	}
	HX_STACK_LINE(319)
	if ((!(this->comp->is_equal_known))){
		HX_STACK_LINE(320)
		return this->testIsEqual();
	}
	HX_STACK_LINE(322)
	if ((!(this->comp->has_same_columns_known))){
		HX_STACK_LINE(323)
		return this->testHasSameColumns();
	}
	HX_STACK_LINE(325)
	this->comp->completed = true;
	HX_STACK_LINE(326)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,compareCore,return )

Void CompareTable_obj::storeIndexes( ){
{
		HX_STACK_FRAME("coopy.CompareTable","storeIndexes",0x84509282,"coopy.CompareTable.storeIndexes","coopy/CompareTable.hx",330,0x02212ed2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(330)
		this->indexes = Array_obj< ::Dynamic >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,storeIndexes,(void))

Array< ::Dynamic > CompareTable_obj::getIndexes( ){
	HX_STACK_FRAME("coopy.CompareTable","getIndexes",0x7a8167ad,"coopy.CompareTable.getIndexes","coopy/CompareTable.hx",334,0x02212ed2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(334)
	return this->indexes;
}


HX_DEFINE_DYNAMIC_FUNC0(CompareTable_obj,getIndexes,return )


CompareTable_obj::CompareTable_obj()
{
}

void CompareTable_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CompareTable);
	HX_MARK_MEMBER_NAME(comp,"comp");
	HX_MARK_MEMBER_NAME(indexes,"indexes");
	HX_MARK_END_CLASS();
}

void CompareTable_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(comp,"comp");
	HX_VISIT_MEMBER_NAME(indexes,"indexes");
}

Dynamic CompareTable_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"comp") ) { return comp; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"align") ) { return align_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"attach") ) { return attach_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isEqual2") ) { return isEqual2_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alignCore") ) { return alignCore_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"alignCore2") ) { return alignCore2_dyn(); }
		if (HX_FIELD_EQ(inName,"getIndexes") ) { return getIndexes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testIsEqual") ) { return testIsEqual_dyn(); }
		if (HX_FIELD_EQ(inName,"compareCore") ) { return compareCore_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"alignColumns") ) { return alignColumns_dyn(); }
		if (HX_FIELD_EQ(inName,"storeIndexes") ) { return storeIndexes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasSameColumns2") ) { return hasSameColumns2_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getComparisonState") ) { return getComparisonState_dyn(); }
		if (HX_FIELD_EQ(inName,"testHasSameColumns") ) { return testHasSameColumns_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CompareTable_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"comp") ) { comp=inValue.Cast< ::coopy::TableComparisonState >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { indexes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CompareTable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("comp"));
	outFields->push(HX_CSTRING("indexes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject,(int)offsetof(CompareTable_obj,comp),HX_CSTRING("comp")},
	{hx::fsObject,(int)offsetof(CompareTable_obj,indexes),HX_CSTRING("indexes")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("comp"),
	HX_CSTRING("indexes"),
	HX_CSTRING("attach"),
	HX_CSTRING("align"),
	HX_CSTRING("getComparisonState"),
	HX_CSTRING("alignCore"),
	HX_CSTRING("alignCore2"),
	HX_CSTRING("alignColumns"),
	HX_CSTRING("testHasSameColumns"),
	HX_CSTRING("hasSameColumns2"),
	HX_CSTRING("testIsEqual"),
	HX_CSTRING("isEqual2"),
	HX_CSTRING("compareCore"),
	HX_CSTRING("storeIndexes"),
	HX_CSTRING("getIndexes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CompareTable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CompareTable_obj::__mClass,"__mClass");
};

#endif

Class CompareTable_obj::__mClass;

void CompareTable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.CompareTable"), hx::TCanCast< CompareTable_obj> ,sStaticFields,sMemberFields,
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

void CompareTable_obj::__boot()
{
}

} // end namespace coopy
