#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_SimpleCell
#include <coopy/SimpleCell.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_TableView
#include <coopy/TableView.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace coopy{

Void TableView_obj::__construct()
{
HX_STACK_PUSH("TableView::new","coopy/TableView.hx",7);
{
}
;
	return null();
}

TableView_obj::~TableView_obj() { }

Dynamic TableView_obj::__CreateEmpty() { return  new TableView_obj; }
hx::ObjectPtr< TableView_obj > TableView_obj::__new()
{  hx::ObjectPtr< TableView_obj > result = new TableView_obj();
	result->__construct();
	return result;}

Dynamic TableView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TableView_obj > result = new TableView_obj();
	result->__construct();
	return result;}

hx::Object *TableView_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::coopy::View_obj)) return operator ::coopy::View_obj *();
	return super::__ToInterface(inType);
}

Dynamic TableView_obj::toDatum( ::String str){
	HX_STACK_PUSH("TableView::toDatum","coopy/TableView.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_ARG(str,"str");
	HX_STACK_LINE(32)
	return ::coopy::SimpleCell_obj::__new(str);
}


HX_DEFINE_DYNAMIC_FUNC1(TableView_obj,toDatum,return )

bool TableView_obj::equals( Dynamic d1,Dynamic d2){
	HX_STACK_PUSH("TableView::equals","coopy/TableView.hx",27);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d1,"d1");
	HX_STACK_ARG(d2,"d2");
	HX_STACK_LINE(28)
	::haxe::Log_obj::trace(HX_CSTRING("TableView.equals called"),hx::SourceInfo(HX_CSTRING("TableView.hx"),28,HX_CSTRING("coopy.TableView"),HX_CSTRING("equals")));
	HX_STACK_LINE(29)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(TableView_obj,equals,return )

bool TableView_obj::hasStructure( Dynamic d){
	HX_STACK_PUSH("TableView::hasStructure","coopy/TableView.hx",23);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(23)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(TableView_obj,hasStructure,return )

::coopy::Table TableView_obj::getTable( Dynamic d){
	HX_STACK_PUSH("TableView::getTable","coopy/TableView.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(19)
	::coopy::Table table = d;		HX_STACK_VAR(table,"table");
	HX_STACK_LINE(20)
	return table;
}


HX_DEFINE_DYNAMIC_FUNC1(TableView_obj,getTable,return )

::coopy::Bag TableView_obj::getBag( Dynamic d){
	HX_STACK_PUSH("TableView::getBag","coopy/TableView.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(14)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TableView_obj,getBag,return )

::String TableView_obj::toString( Dynamic d){
	HX_STACK_PUSH("TableView::toString","coopy/TableView.hx",10);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(10)
	return (HX_CSTRING("") + ::Std_obj::string(d));
}


HX_DEFINE_DYNAMIC_FUNC1(TableView_obj,toString,return )


TableView_obj::TableView_obj()
{
}

void TableView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TableView);
	HX_MARK_END_CLASS();
}

void TableView_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic TableView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"getBag") ) { return getBag_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toDatum") ) { return toDatum_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getTable") ) { return getTable_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"hasStructure") ) { return hasStructure_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TableView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TableView_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toDatum"),
	HX_CSTRING("equals"),
	HX_CSTRING("hasStructure"),
	HX_CSTRING("getTable"),
	HX_CSTRING("getBag"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TableView_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TableView_obj::__mClass,"__mClass");
};

Class TableView_obj::__mClass;

void TableView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.TableView"), hx::TCanCast< TableView_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TableView_obj::__boot()
{
}

} // end namespace coopy
