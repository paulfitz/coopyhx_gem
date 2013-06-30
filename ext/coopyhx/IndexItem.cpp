#include <hxcpp.h>

#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
namespace coopy{

Void IndexItem_obj::__construct()
{
HX_STACK_PUSH("IndexItem::new","coopy/IndexItem.hx",8);
{
}
;
	return null();
}

IndexItem_obj::~IndexItem_obj() { }

Dynamic IndexItem_obj::__CreateEmpty() { return  new IndexItem_obj; }
hx::ObjectPtr< IndexItem_obj > IndexItem_obj::__new()
{  hx::ObjectPtr< IndexItem_obj > result = new IndexItem_obj();
	result->__construct();
	return result;}

Dynamic IndexItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IndexItem_obj > result = new IndexItem_obj();
	result->__construct();
	return result;}

int IndexItem_obj::add( int i){
	HX_STACK_PUSH("IndexItem::add","coopy/IndexItem.hx",11);
	HX_STACK_THIS(this);
	HX_STACK_ARG(i,"i");
	HX_STACK_LINE(12)
	if (((this->lst == null()))){
		HX_STACK_LINE(12)
		this->lst = Array_obj< int >::__new();
	}
	HX_STACK_LINE(13)
	this->lst->push(i);
	HX_STACK_LINE(14)
	return this->lst->length;
}


HX_DEFINE_DYNAMIC_FUNC1(IndexItem_obj,add,return )


IndexItem_obj::IndexItem_obj()
{
}

void IndexItem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IndexItem);
	HX_MARK_MEMBER_NAME(lst,"lst");
	HX_MARK_END_CLASS();
}

void IndexItem_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lst,"lst");
}

Dynamic IndexItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"lst") ) { return lst; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IndexItem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lst") ) { lst=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IndexItem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lst"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("add"),
	HX_CSTRING("lst"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IndexItem_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IndexItem_obj::__mClass,"__mClass");
};

Class IndexItem_obj::__mClass;

void IndexItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.IndexItem"), hx::TCanCast< IndexItem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IndexItem_obj::__boot()
{
}

} // end namespace coopy
