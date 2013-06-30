#include <hxcpp.h>

#ifndef INCLUDED_coopy_Unit
#include <coopy/Unit.h>
#endif
namespace coopy{

Void Unit_obj::__construct(int l,int r,hx::Null< int >  __o_p)
{
HX_STACK_PUSH("Unit::new","coopy/Unit.hx",10);
int p = __o_p.Default(-2);
{
	HX_STACK_LINE(11)
	this->l = l;
	HX_STACK_LINE(12)
	this->r = r;
	HX_STACK_LINE(13)
	this->p = p;
}
;
	return null();
}

Unit_obj::~Unit_obj() { }

Dynamic Unit_obj::__CreateEmpty() { return  new Unit_obj; }
hx::ObjectPtr< Unit_obj > Unit_obj::__new(int l,int r,hx::Null< int >  __o_p)
{  hx::ObjectPtr< Unit_obj > result = new Unit_obj();
	result->__construct(l,r,__o_p);
	return result;}

Dynamic Unit_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Unit_obj > result = new Unit_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Unit_obj::toString( ){
	HX_STACK_PUSH("Unit::toString","coopy/Unit.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_LINE(26)
	if (((this->p >= (int)-1))){
		HX_STACK_LINE(26)
		return ((((::coopy::Unit_obj::describe(this->p) + HX_CSTRING("|")) + ::coopy::Unit_obj::describe(this->l)) + HX_CSTRING(":")) + ::coopy::Unit_obj::describe(this->r));
	}
	HX_STACK_LINE(27)
	return ((::coopy::Unit_obj::describe(this->l) + HX_CSTRING(":")) + ::coopy::Unit_obj::describe(this->r));
}


HX_DEFINE_DYNAMIC_FUNC0(Unit_obj,toString,return )

int Unit_obj::lp( ){
	HX_STACK_PUSH("Unit::lp","coopy/Unit.hx",16);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	return (  (((this->p == (int)-2))) ? int(this->l) : int(this->p) );
}


HX_DEFINE_DYNAMIC_FUNC0(Unit_obj,lp,return )

::String Unit_obj::describe( int i){
	HX_STACK_PUSH("Unit::describe","coopy/Unit.hx",21);
	HX_STACK_ARG(i,"i");
	HX_STACK_LINE(21)
	return (  (((i >= (int)0))) ? ::String((HX_CSTRING("") + i)) : ::String(HX_CSTRING("-")) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Unit_obj,describe,return )


Unit_obj::Unit_obj()
{
}

void Unit_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Unit);
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(r,"r");
	HX_MARK_MEMBER_NAME(l,"l");
	HX_MARK_END_CLASS();
}

void Unit_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(p,"p");
	HX_VISIT_MEMBER_NAME(r,"r");
	HX_VISIT_MEMBER_NAME(l,"l");
}

Dynamic Unit_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"l") ) { return l; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"lp") ) { return lp_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"describe") ) { return describe_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Unit_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"r") ) { r=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"l") ) { l=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Unit_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p"));
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("l"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("describe"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("lp"),
	HX_CSTRING("p"),
	HX_CSTRING("r"),
	HX_CSTRING("l"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Unit_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Unit_obj::__mClass,"__mClass");
};

Class Unit_obj::__mClass;

void Unit_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Unit"), hx::TCanCast< Unit_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Unit_obj::__boot()
{
}

} // end namespace coopy
