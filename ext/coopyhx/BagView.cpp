#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_BagView
#include <coopy/BagView.h>
#endif
#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_SimpleCell
#include <coopy/SimpleCell.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace coopy{

Void BagView_obj::__construct()
{
HX_STACK_PUSH("BagView::new","coopy/BagView.hx",6);
{
}
;
	return null();
}

BagView_obj::~BagView_obj() { }

Dynamic BagView_obj::__CreateEmpty() { return  new BagView_obj; }
hx::ObjectPtr< BagView_obj > BagView_obj::__new()
{  hx::ObjectPtr< BagView_obj > result = new BagView_obj();
	result->__construct();
	return result;}

Dynamic BagView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BagView_obj > result = new BagView_obj();
	result->__construct();
	return result;}

hx::Object *BagView_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::coopy::View_obj)) return operator ::coopy::View_obj *();
	return super::__ToInterface(inType);
}

::coopy::Datum BagView_obj::toDatum( ::String str){
	HX_STACK_PUSH("BagView::toDatum","coopy/BagView.hx",31);
	HX_STACK_THIS(this);
	HX_STACK_ARG(str,"str");
	HX_STACK_LINE(32)
	if (((str == null()))){
		HX_STACK_LINE(32)
		return null();
	}
	HX_STACK_LINE(33)
	return ::coopy::SimpleCell_obj::__new(str);
}


HX_DEFINE_DYNAMIC_FUNC1(BagView_obj,toDatum,return )

bool BagView_obj::equals( ::coopy::Datum d1,::coopy::Datum d2){
	HX_STACK_PUSH("BagView::equals","coopy/BagView.hx",26);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d1,"d1");
	HX_STACK_ARG(d2,"d2");
	HX_STACK_LINE(27)
	::haxe::Log_obj::trace(HX_CSTRING("BagView.equals called"),hx::SourceInfo(HX_CSTRING("BagView.hx"),27,HX_CSTRING("coopy.BagView"),HX_CSTRING("equals")));
	HX_STACK_LINE(28)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(BagView_obj,equals,return )

bool BagView_obj::hasStructure( ::coopy::Datum d){
	HX_STACK_PUSH("BagView::hasStructure","coopy/BagView.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(22)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(BagView_obj,hasStructure,return )

::coopy::Table BagView_obj::getTable( ::coopy::Datum d){
	HX_STACK_PUSH("BagView::getTable","coopy/BagView.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(18)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BagView_obj,getTable,return )

::coopy::Bag BagView_obj::getBag( ::coopy::Datum d){
	HX_STACK_PUSH("BagView::getBag","coopy/BagView.hx",13);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(14)
	::coopy::Bag bag = d;		HX_STACK_VAR(bag,"bag");
	HX_STACK_LINE(15)
	return bag;
}


HX_DEFINE_DYNAMIC_FUNC1(BagView_obj,getBag,return )

::String BagView_obj::toString( ::coopy::Datum d){
	HX_STACK_PUSH("BagView::toString","coopy/BagView.hx",9);
	HX_STACK_THIS(this);
	HX_STACK_ARG(d,"d");
	HX_STACK_LINE(9)
	return (HX_CSTRING("") + ::Std_obj::string(d));
}


HX_DEFINE_DYNAMIC_FUNC1(BagView_obj,toString,return )


BagView_obj::BagView_obj()
{
}

void BagView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BagView);
	HX_MARK_END_CLASS();
}

void BagView_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BagView_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic BagView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BagView_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(BagView_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BagView_obj::__mClass,"__mClass");
};

Class BagView_obj::__mClass;

void BagView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.BagView"), hx::TCanCast< BagView_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BagView_obj::__boot()
{
}

} // end namespace coopy
