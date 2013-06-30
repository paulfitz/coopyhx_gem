#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_Compare
#include <coopy/Compare.h>
#endif
#ifndef INCLUDED_coopy_CompareFlags
#include <coopy/CompareFlags.h>
#endif
#ifndef INCLUDED_coopy_CompareTable
#include <coopy/CompareTable.h>
#endif
#ifndef INCLUDED_coopy_Coopy
#include <coopy/Coopy.h>
#endif
#ifndef INCLUDED_coopy_Csv
#include <coopy/Csv.h>
#endif
#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_DiffRender
#include <coopy/DiffRender.h>
#endif
#ifndef INCLUDED_coopy_HighlightPatch
#include <coopy/HighlightPatch.h>
#endif
#ifndef INCLUDED_coopy_Index
#include <coopy/Index.h>
#endif
#ifndef INCLUDED_coopy_Report
#include <coopy/Report.h>
#endif
#ifndef INCLUDED_coopy_Row
#include <coopy/Row.h>
#endif
#ifndef INCLUDED_coopy_SimpleCell
#include <coopy/SimpleCell.h>
#endif
#ifndef INCLUDED_coopy_SimpleTable
#include <coopy/SimpleTable.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_TableComparisonState
#include <coopy/TableComparisonState.h>
#endif
#ifndef INCLUDED_coopy_TableDiff
#include <coopy/TableDiff.h>
#endif
#ifndef INCLUDED_coopy_TableModifier
#include <coopy/TableModifier.h>
#endif
#ifndef INCLUDED_coopy_TableView
#include <coopy/TableView.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_coopy_ViewedDatum
#include <coopy/ViewedDatum.h>
#endif
#ifndef INCLUDED_coopy_Viterbi
#include <coopy/Viterbi.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace coopy{

Void Coopy_obj::__construct()
{
HX_STACK_PUSH("Coopy::new","coopy/Coopy.hx",9);
{
}
;
	return null();
}

Coopy_obj::~Coopy_obj() { }

Dynamic Coopy_obj::__CreateEmpty() { return  new Coopy_obj; }
hx::ObjectPtr< Coopy_obj > Coopy_obj::__new()
{  hx::ObjectPtr< Coopy_obj > result = new Coopy_obj();
	result->__construct();
	return result;}

Dynamic Coopy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Coopy_obj > result = new Coopy_obj();
	result->__construct();
	return result;}

::coopy::CompareTable Coopy_obj::compareTables( ::coopy::Table local,::coopy::Table remote){
	HX_STACK_PUSH("Coopy::compareTables","coopy/Coopy.hx",12);
	HX_STACK_ARG(local,"local");
	HX_STACK_ARG(remote,"remote");
	HX_STACK_LINE(13)
	::coopy::CompareTable ct = ::coopy::CompareTable_obj::__new();		HX_STACK_VAR(ct,"ct");
	HX_STACK_LINE(14)
	::coopy::TableComparisonState comp = ::coopy::TableComparisonState_obj::__new();		HX_STACK_VAR(comp,"comp");
	HX_STACK_LINE(15)
	comp->a = local;
	HX_STACK_LINE(16)
	comp->b = remote;
	HX_STACK_LINE(17)
	ct->attach(comp);
	HX_STACK_LINE(18)
	return ct;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Coopy_obj,compareTables,return )

::coopy::CompareTable Coopy_obj::compareTables3( ::coopy::Table parent,::coopy::Table local,::coopy::Table remote){
	HX_STACK_PUSH("Coopy::compareTables3","coopy/Coopy.hx",21);
	HX_STACK_ARG(parent,"parent");
	HX_STACK_ARG(local,"local");
	HX_STACK_ARG(remote,"remote");
	HX_STACK_LINE(22)
	::coopy::CompareTable ct = ::coopy::CompareTable_obj::__new();		HX_STACK_VAR(ct,"ct");
	HX_STACK_LINE(23)
	::coopy::TableComparisonState comp = ::coopy::TableComparisonState_obj::__new();		HX_STACK_VAR(comp,"comp");
	HX_STACK_LINE(24)
	comp->p = parent;
	HX_STACK_LINE(25)
	comp->a = local;
	HX_STACK_LINE(26)
	comp->b = remote;
	HX_STACK_LINE(27)
	ct->attach(comp);
	HX_STACK_LINE(28)
	return ct;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Coopy_obj,compareTables3,return )

int Coopy_obj::randomTests( ){
	HX_STACK_PUSH("Coopy::randomTests","coopy/Coopy.hx",31);
	HX_STACK_LINE(34)
	::coopy::SimpleTable st = ::coopy::SimpleTable_obj::__new((int)15,(int)6);		HX_STACK_VAR(st,"st");
	HX_STACK_LINE(35)
	::coopy::Table tab = st;		HX_STACK_VAR(tab,"tab");
	HX_STACK_LINE(36)
	::coopy::Bag bag = st;		HX_STACK_VAR(bag,"bag");
	HX_STACK_LINE(37)
	::haxe::Log_obj::trace((((HX_CSTRING("table size is ") + tab->__Field(HX_CSTRING("get_width"),true)()) + HX_CSTRING("x")) + tab->__Field(HX_CSTRING("get_height"),true)()),hx::SourceInfo(HX_CSTRING("Coopy.hx"),37,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(38)
	tab->setCell((int)3,(int)4,::coopy::SimpleCell_obj::__new((int)33));
	HX_STACK_LINE(39)
	::haxe::Log_obj::trace((HX_CSTRING("element is ") + ::Std_obj::string(tab->getCell((int)3,(int)4))),hx::SourceInfo(HX_CSTRING("Coopy.hx"),39,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(41)
	::haxe::Log_obj::trace((HX_CSTRING("table as bag is ") + ::Std_obj::string(bag)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),41,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(42)
	::coopy::Datum datum = bag->getItem((int)4);		HX_STACK_VAR(datum,"datum");
	HX_STACK_LINE(43)
	::coopy::Bag row = bag->getItemView()->getBag(datum);		HX_STACK_VAR(row,"row");
	HX_STACK_LINE(44)
	::haxe::Log_obj::trace((HX_CSTRING("element is ") + ::Std_obj::string(row->getItem((int)3))),hx::SourceInfo(HX_CSTRING("Coopy.hx"),44,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(46)
	::coopy::Compare compare = ::coopy::Compare_obj::__new();		HX_STACK_VAR(compare,"compare");
	HX_STACK_LINE(47)
	::coopy::ViewedDatum d1 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)10));		HX_STACK_VAR(d1,"d1");
	HX_STACK_LINE(48)
	::coopy::ViewedDatum d2 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)10));		HX_STACK_VAR(d2,"d2");
	HX_STACK_LINE(49)
	::coopy::ViewedDatum d3 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)20));		HX_STACK_VAR(d3,"d3");
	HX_STACK_LINE(50)
	::coopy::Report report = ::coopy::Report_obj::__new();		HX_STACK_VAR(report,"report");
	HX_STACK_LINE(51)
	compare->compare(d1,d2,d3,report);
	HX_STACK_LINE(52)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),52,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(53)
	d2 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)50));
	HX_STACK_LINE(54)
	report->clear();
	HX_STACK_LINE(55)
	compare->compare(d1,d2,d3,report);
	HX_STACK_LINE(56)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),56,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(57)
	d2 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)20));
	HX_STACK_LINE(58)
	report->clear();
	HX_STACK_LINE(59)
	compare->compare(d1,d2,d3,report);
	HX_STACK_LINE(60)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),60,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(61)
	d1 = ::coopy::ViewedDatum_obj::getSimpleView(::coopy::SimpleCell_obj::__new((int)20));
	HX_STACK_LINE(62)
	report->clear();
	HX_STACK_LINE(63)
	compare->compare(d1,d2,d3,report);
	HX_STACK_LINE(64)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),64,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(66)
	::coopy::TableView tv = ::coopy::TableView_obj::__new();		HX_STACK_VAR(tv,"tv");
	HX_STACK_LINE(68)
	::coopy::TableComparisonState comp = ::coopy::TableComparisonState_obj::__new();		HX_STACK_VAR(comp,"comp");
	HX_STACK_LINE(69)
	::coopy::CompareTable ct = ::coopy::CompareTable_obj::__new();		HX_STACK_VAR(ct,"ct");
	HX_STACK_LINE(70)
	comp->a = st;
	HX_STACK_LINE(71)
	comp->b = st;
	HX_STACK_LINE(72)
	ct->attach(comp);
	HX_STACK_LINE(74)
	::haxe::Log_obj::trace(HX_CSTRING("comparing tables"),hx::SourceInfo(HX_CSTRING("Coopy.hx"),74,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(75)
	::coopy::SimpleTable t1 = ::coopy::SimpleTable_obj::__new((int)3,(int)2);		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(76)
	::coopy::SimpleTable t2 = ::coopy::SimpleTable_obj::__new((int)3,(int)2);		HX_STACK_VAR(t2,"t2");
	HX_STACK_LINE(77)
	::coopy::SimpleTable t3 = ::coopy::SimpleTable_obj::__new((int)3,(int)2);		HX_STACK_VAR(t3,"t3");
	HX_STACK_LINE(78)
	::coopy::ViewedDatum dt1 = ::coopy::ViewedDatum_obj::__new(t1,::coopy::TableView_obj::__new());		HX_STACK_VAR(dt1,"dt1");
	HX_STACK_LINE(79)
	::coopy::ViewedDatum dt2 = ::coopy::ViewedDatum_obj::__new(t2,::coopy::TableView_obj::__new());		HX_STACK_VAR(dt2,"dt2");
	HX_STACK_LINE(80)
	::coopy::ViewedDatum dt3 = ::coopy::ViewedDatum_obj::__new(t3,::coopy::TableView_obj::__new());		HX_STACK_VAR(dt3,"dt3");
	HX_STACK_LINE(81)
	compare->compare(dt1,dt2,dt3,report);
	HX_STACK_LINE(82)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),82,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(83)
	t3->setCell((int)1,(int)1,::coopy::SimpleCell_obj::__new(HX_CSTRING("hello")));
	HX_STACK_LINE(84)
	compare->compare(dt1,dt2,dt3,report);
	HX_STACK_LINE(85)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),85,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(86)
	t1->setCell((int)1,(int)1,::coopy::SimpleCell_obj::__new(HX_CSTRING("hello")));
	HX_STACK_LINE(87)
	compare->compare(dt1,dt2,dt3,report);
	HX_STACK_LINE(88)
	::haxe::Log_obj::trace((HX_CSTRING("report is ") + ::Std_obj::string(report)),hx::SourceInfo(HX_CSTRING("Coopy.hx"),88,HX_CSTRING("coopy.Coopy"),HX_CSTRING("randomTests")));
	HX_STACK_LINE(90)
	::coopy::Viterbi v = ::coopy::Viterbi_obj::__new();		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(91)
	::coopy::TableDiff td = ::coopy::TableDiff_obj::__new(null(),null());		HX_STACK_VAR(td,"td");
	HX_STACK_LINE(92)
	::coopy::Index idx = ::coopy::Index_obj::__new();		HX_STACK_VAR(idx,"idx");
	HX_STACK_LINE(93)
	::coopy::DiffRender dr = ::coopy::DiffRender_obj::__new();		HX_STACK_VAR(dr,"dr");
	HX_STACK_LINE(94)
	::coopy::CompareFlags cf = ::coopy::CompareFlags_obj::__new();		HX_STACK_VAR(cf,"cf");
	HX_STACK_LINE(95)
	::coopy::HighlightPatch hp = ::coopy::HighlightPatch_obj::__new(null(),null());		HX_STACK_VAR(hp,"hp");
	HX_STACK_LINE(96)
	::coopy::Csv csv = ::coopy::Csv_obj::__new();		HX_STACK_VAR(csv,"csv");
	HX_STACK_LINE(97)
	::coopy::TableModifier tm = ::coopy::TableModifier_obj::__new(null());		HX_STACK_VAR(tm,"tm");
	HX_STACK_LINE(99)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Coopy_obj,randomTests,return )

int Coopy_obj::main( ){
	HX_STACK_PUSH("Coopy::main","coopy/Coopy.hx",258);
	HX_STACK_LINE(258)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Coopy_obj,main,return )

Void Coopy_obj::show( ::coopy::Table t){
{
		HX_STACK_PUSH("Coopy::show","coopy/Coopy.hx",267);
		HX_STACK_ARG(t,"t");
		HX_STACK_LINE(268)
		int w = t->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(269)
		int h = t->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(270)
		::String txt = HX_CSTRING("");		HX_STACK_VAR(txt,"txt");
		HX_STACK_LINE(271)
		{
			HX_STACK_LINE(271)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(271)
			while(((_g < h))){
				HX_STACK_LINE(271)
				int y = (_g)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(272)
				{
					HX_STACK_LINE(272)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(272)
					while(((_g1 < w))){
						HX_STACK_LINE(272)
						int x = (_g1)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(273)
						hx::AddEq(txt,::Std_obj::string(t->getCell(x,y)));
						HX_STACK_LINE(274)
						hx::AddEq(txt,HX_CSTRING(" "));
					}
				}
				HX_STACK_LINE(276)
				hx::AddEq(txt,HX_CSTRING("\n"));
			}
		}
		HX_STACK_LINE(278)
		::haxe::Log_obj::trace(txt,hx::SourceInfo(HX_CSTRING("Coopy.hx"),278,HX_CSTRING("coopy.Coopy"),HX_CSTRING("show")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Coopy_obj,show,(void))

Dynamic Coopy_obj::jsonify( ::coopy::Table t){
	HX_STACK_PUSH("Coopy::jsonify","coopy/Coopy.hx",282);
	HX_STACK_ARG(t,"t");
	HX_STACK_LINE(283)
	::haxe::ds::StringMap workbook = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(workbook,"workbook");
	HX_STACK_LINE(284)
	Dynamic sheet = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(sheet,"sheet");
	HX_STACK_LINE(285)
	int w = t->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(286)
	int h = t->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(287)
	::String txt = HX_CSTRING("");		HX_STACK_VAR(txt,"txt");
	HX_STACK_LINE(288)
	{
		HX_STACK_LINE(288)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(288)
		while(((_g < h))){
			HX_STACK_LINE(288)
			int y = (_g)++;		HX_STACK_VAR(y,"y");
			HX_STACK_LINE(289)
			Dynamic row = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(290)
			{
				HX_STACK_LINE(290)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(290)
				while(((_g1 < w))){
					HX_STACK_LINE(290)
					int x = (_g1)++;		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(291)
					::coopy::Datum v = t->getCell(x,y);		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(292)
					if (((v != null()))){
						HX_STACK_LINE(292)
						row->__Field(HX_CSTRING("push"),true)(v->toString());
					}
					else{
						HX_STACK_LINE(294)
						row->__Field(HX_CSTRING("push"),true)(null());
					}
				}
			}
			HX_STACK_LINE(298)
			sheet->__Field(HX_CSTRING("push"),true)(row);
		}
	}
	HX_STACK_LINE(300)
	workbook->set(HX_CSTRING("sheet"),sheet);
	HX_STACK_LINE(301)
	return workbook;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Coopy_obj,jsonify,return )


Coopy_obj::Coopy_obj()
{
}

void Coopy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Coopy);
	HX_MARK_MEMBER_NAME(format_preference,"format_preference");
	HX_MARK_END_CLASS();
}

void Coopy_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(format_preference,"format_preference");
}

Dynamic Coopy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"jsonify") ) { return jsonify_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"randomTests") ) { return randomTests_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"compareTables") ) { return compareTables_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"compareTables3") ) { return compareTables3_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"format_preference") ) { return format_preference; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Coopy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"format_preference") ) { format_preference=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Coopy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("format_preference"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compareTables"),
	HX_CSTRING("compareTables3"),
	HX_CSTRING("randomTests"),
	HX_CSTRING("main"),
	HX_CSTRING("show"),
	HX_CSTRING("jsonify"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("format_preference"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Coopy_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Coopy_obj::__mClass,"__mClass");
};

Class Coopy_obj::__mClass;

void Coopy_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Coopy"), hx::TCanCast< Coopy_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Coopy_obj::__boot()
{
}

} // end namespace coopy