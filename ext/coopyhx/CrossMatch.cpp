#include <hxcpp.h>

#ifndef INCLUDED_coopy_CrossMatch
#include <coopy/CrossMatch.h>
#endif
#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
namespace coopy{

Void CrossMatch_obj::__construct()
{
HX_STACK_PUSH("CrossMatch::new","coopy/CrossMatch.hx",11);
{
}
;
	return null();
}

CrossMatch_obj::~CrossMatch_obj() { }

Dynamic CrossMatch_obj::__CreateEmpty() { return  new CrossMatch_obj; }
hx::ObjectPtr< CrossMatch_obj > CrossMatch_obj::__new()
{  hx::ObjectPtr< CrossMatch_obj > result = new CrossMatch_obj();
	result->__construct();
	return result;}

Dynamic CrossMatch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CrossMatch_obj > result = new CrossMatch_obj();
	result->__construct();
	return result;}


CrossMatch_obj::CrossMatch_obj()
{
}

void CrossMatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CrossMatch);
	HX_MARK_MEMBER_NAME(item_b,"item_b");
	HX_MARK_MEMBER_NAME(item_a,"item_a");
	HX_MARK_MEMBER_NAME(spot_b,"spot_b");
	HX_MARK_MEMBER_NAME(spot_a,"spot_a");
	HX_MARK_END_CLASS();
}

void CrossMatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(item_b,"item_b");
	HX_VISIT_MEMBER_NAME(item_a,"item_a");
	HX_VISIT_MEMBER_NAME(spot_b,"spot_b");
	HX_VISIT_MEMBER_NAME(spot_a,"spot_a");
}

Dynamic CrossMatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"item_b") ) { return item_b; }
		if (HX_FIELD_EQ(inName,"item_a") ) { return item_a; }
		if (HX_FIELD_EQ(inName,"spot_b") ) { return spot_b; }
		if (HX_FIELD_EQ(inName,"spot_a") ) { return spot_a; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CrossMatch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"item_b") ) { item_b=inValue.Cast< ::coopy::IndexItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"item_a") ) { item_a=inValue.Cast< ::coopy::IndexItem >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spot_b") ) { spot_b=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spot_a") ) { spot_a=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CrossMatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("item_b"));
	outFields->push(HX_CSTRING("item_a"));
	outFields->push(HX_CSTRING("spot_b"));
	outFields->push(HX_CSTRING("spot_a"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("item_b"),
	HX_CSTRING("item_a"),
	HX_CSTRING("spot_b"),
	HX_CSTRING("spot_a"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CrossMatch_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CrossMatch_obj::__mClass,"__mClass");
};

Class CrossMatch_obj::__mClass;

void CrossMatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.CrossMatch"), hx::TCanCast< CrossMatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CrossMatch_obj::__boot()
{
}

} // end namespace coopy
