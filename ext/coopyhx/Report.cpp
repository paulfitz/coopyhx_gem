#include <hxcpp.h>

#ifndef INCLUDED_coopy_Change
#include <coopy/Change.h>
#endif
#ifndef INCLUDED_coopy_Report
#include <coopy/Report.h>
#endif
namespace coopy{

Void Report_obj::__construct()
{
HX_STACK_PUSH("Report::new","coopy/Report.hx",7);
{
	HX_STACK_LINE(7)
	this->changes = Array_obj< ::coopy::Change >::__new();
}
;
	return null();
}

Report_obj::~Report_obj() { }

Dynamic Report_obj::__CreateEmpty() { return  new Report_obj; }
hx::ObjectPtr< Report_obj > Report_obj::__new()
{  hx::ObjectPtr< Report_obj > result = new Report_obj();
	result->__construct();
	return result;}

Dynamic Report_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Report_obj > result = new Report_obj();
	result->__construct();
	return result;}

Void Report_obj::clear( ){
{
		HX_STACK_PUSH("Report::clear","coopy/Report.hx",17);
		HX_STACK_THIS(this);
		HX_STACK_LINE(17)
		this->changes = Array_obj< ::coopy::Change >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Report_obj,clear,(void))

::String Report_obj::toString( ){
	HX_STACK_PUSH("Report::toString","coopy/Report.hx",13);
	HX_STACK_THIS(this);
	HX_STACK_LINE(13)
	return this->changes->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Report_obj,toString,return )


Report_obj::Report_obj()
{
}

void Report_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Report);
	HX_MARK_MEMBER_NAME(changes,"changes");
	HX_MARK_END_CLASS();
}

void Report_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(changes,"changes");
}

Dynamic Report_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"changes") ) { return changes; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Report_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"changes") ) { changes=inValue.Cast< Array< ::coopy::Change > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Report_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("changes"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clear"),
	HX_CSTRING("toString"),
	HX_CSTRING("changes"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Report_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Report_obj::__mClass,"__mClass");
};

Class Report_obj::__mClass;

void Report_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Report"), hx::TCanCast< Report_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Report_obj::__boot()
{
}

} // end namespace coopy
