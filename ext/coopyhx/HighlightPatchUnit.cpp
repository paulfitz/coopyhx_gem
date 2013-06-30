#include <hxcpp.h>

#ifndef INCLUDED_coopy_HighlightPatchUnit
#include <coopy/HighlightPatchUnit.h>
#endif
namespace coopy{

Void HighlightPatchUnit_obj::__construct()
{
HX_STACK_PUSH("HighlightPatchUnit::new","coopy/HighlightPatchUnit.hx",14);
{
	HX_STACK_LINE(15)
	this->add = false;
	HX_STACK_LINE(16)
	this->rem = false;
	HX_STACK_LINE(17)
	this->sourceRow = (int)-1;
	HX_STACK_LINE(18)
	this->sourceRow2 = (int)-1;
	HX_STACK_LINE(19)
	this->patchRow = (int)-1;
}
;
	return null();
}

HighlightPatchUnit_obj::~HighlightPatchUnit_obj() { }

Dynamic HighlightPatchUnit_obj::__CreateEmpty() { return  new HighlightPatchUnit_obj; }
hx::ObjectPtr< HighlightPatchUnit_obj > HighlightPatchUnit_obj::__new()
{  hx::ObjectPtr< HighlightPatchUnit_obj > result = new HighlightPatchUnit_obj();
	result->__construct();
	return result;}

Dynamic HighlightPatchUnit_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HighlightPatchUnit_obj > result = new HighlightPatchUnit_obj();
	result->__construct();
	return result;}

::String HighlightPatchUnit_obj::toString( ){
	HX_STACK_PUSH("HighlightPatchUnit::toString","coopy/HighlightPatchUnit.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_LINE(22)
	return ((((((((  ((this->add)) ? ::String(HX_CSTRING("insert")) : ::String((  ((this->rem)) ? ::String(HX_CSTRING("delete")) : ::String(HX_CSTRING("update")) )) )) + HX_CSTRING(" ")) + this->sourceRow) + HX_CSTRING(":")) + this->sourceRow2) + HX_CSTRING(" ")) + this->patchRow);
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatchUnit_obj,toString,return )


HighlightPatchUnit_obj::HighlightPatchUnit_obj()
{
}

void HighlightPatchUnit_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HighlightPatchUnit);
	HX_MARK_MEMBER_NAME(patchRow,"patchRow");
	HX_MARK_MEMBER_NAME(sourceRow2,"sourceRow2");
	HX_MARK_MEMBER_NAME(sourceRow,"sourceRow");
	HX_MARK_MEMBER_NAME(pad,"pad");
	HX_MARK_MEMBER_NAME(rem,"rem");
	HX_MARK_MEMBER_NAME(add,"add");
	HX_MARK_END_CLASS();
}

void HighlightPatchUnit_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(patchRow,"patchRow");
	HX_VISIT_MEMBER_NAME(sourceRow2,"sourceRow2");
	HX_VISIT_MEMBER_NAME(sourceRow,"sourceRow");
	HX_VISIT_MEMBER_NAME(pad,"pad");
	HX_VISIT_MEMBER_NAME(rem,"rem");
	HX_VISIT_MEMBER_NAME(add,"add");
}

Dynamic HighlightPatchUnit_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pad") ) { return pad; }
		if (HX_FIELD_EQ(inName,"rem") ) { return rem; }
		if (HX_FIELD_EQ(inName,"add") ) { return add; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"patchRow") ) { return patchRow; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sourceRow") ) { return sourceRow; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceRow2") ) { return sourceRow2; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HighlightPatchUnit_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pad") ) { pad=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rem") ) { rem=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"add") ) { add=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"patchRow") ) { patchRow=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sourceRow") ) { sourceRow=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sourceRow2") ) { sourceRow2=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HighlightPatchUnit_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("patchRow"));
	outFields->push(HX_CSTRING("sourceRow2"));
	outFields->push(HX_CSTRING("sourceRow"));
	outFields->push(HX_CSTRING("pad"));
	outFields->push(HX_CSTRING("rem"));
	outFields->push(HX_CSTRING("add"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("patchRow"),
	HX_CSTRING("sourceRow2"),
	HX_CSTRING("sourceRow"),
	HX_CSTRING("pad"),
	HX_CSTRING("rem"),
	HX_CSTRING("add"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HighlightPatchUnit_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HighlightPatchUnit_obj::__mClass,"__mClass");
};

Class HighlightPatchUnit_obj::__mClass;

void HighlightPatchUnit_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.HighlightPatchUnit"), hx::TCanCast< HighlightPatchUnit_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HighlightPatchUnit_obj::__boot()
{
}

} // end namespace coopy
