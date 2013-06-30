#include <hxcpp.h>

#ifndef INCLUDED_coopy_CompareFlags
#include <coopy/CompareFlags.h>
#endif
namespace coopy{

Void CompareFlags_obj::__construct()
{
HX_STACK_PUSH("CompareFlags::new","coopy/CompareFlags.hx",11);
{
	HX_STACK_LINE(12)
	this->always_show_header = true;
	HX_STACK_LINE(13)
	this->show_unchanged = false;
	HX_STACK_LINE(14)
	this->unchanged_context = (int)1;
}
;
	return null();
}

CompareFlags_obj::~CompareFlags_obj() { }

Dynamic CompareFlags_obj::__CreateEmpty() { return  new CompareFlags_obj; }
hx::ObjectPtr< CompareFlags_obj > CompareFlags_obj::__new()
{  hx::ObjectPtr< CompareFlags_obj > result = new CompareFlags_obj();
	result->__construct();
	return result;}

Dynamic CompareFlags_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CompareFlags_obj > result = new CompareFlags_obj();
	result->__construct();
	return result;}


CompareFlags_obj::CompareFlags_obj()
{
}

void CompareFlags_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CompareFlags);
	HX_MARK_MEMBER_NAME(unchanged_context,"unchanged_context");
	HX_MARK_MEMBER_NAME(show_unchanged,"show_unchanged");
	HX_MARK_MEMBER_NAME(always_show_header,"always_show_header");
	HX_MARK_END_CLASS();
}

void CompareFlags_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(unchanged_context,"unchanged_context");
	HX_VISIT_MEMBER_NAME(show_unchanged,"show_unchanged");
	HX_VISIT_MEMBER_NAME(always_show_header,"always_show_header");
}

Dynamic CompareFlags_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"show_unchanged") ) { return show_unchanged; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unchanged_context") ) { return unchanged_context; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"always_show_header") ) { return always_show_header; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CompareFlags_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"show_unchanged") ) { show_unchanged=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"unchanged_context") ) { unchanged_context=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"always_show_header") ) { always_show_header=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CompareFlags_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("unchanged_context"));
	outFields->push(HX_CSTRING("show_unchanged"));
	outFields->push(HX_CSTRING("always_show_header"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("unchanged_context"),
	HX_CSTRING("show_unchanged"),
	HX_CSTRING("always_show_header"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CompareFlags_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CompareFlags_obj::__mClass,"__mClass");
};

Class CompareFlags_obj::__mClass;

void CompareFlags_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.CompareFlags"), hx::TCanCast< CompareFlags_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CompareFlags_obj::__boot()
{
}

} // end namespace coopy
