#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_coopy_Bag
#include <coopy/Bag.h>
#endif
#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_SimpleRow
#include <coopy/SimpleRow.h>
#endif
#ifndef INCLUDED_coopy_SimpleView
#include <coopy/SimpleView.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
namespace coopy{

Void SimpleRow_obj::__construct(::coopy::Table tab,int row_id)
{
HX_STACK_PUSH("SimpleRow::new","coopy/SimpleRow.hx",10);
{
	HX_STACK_LINE(11)
	this->tab = tab;
	HX_STACK_LINE(12)
	this->row_id = row_id;
	HX_STACK_LINE(13)
	this->bag = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

SimpleRow_obj::~SimpleRow_obj() { }

Dynamic SimpleRow_obj::__CreateEmpty() { return  new SimpleRow_obj; }
hx::ObjectPtr< SimpleRow_obj > SimpleRow_obj::__new(::coopy::Table tab,int row_id)
{  hx::ObjectPtr< SimpleRow_obj > result = new SimpleRow_obj();
	result->__construct(tab,row_id);
	return result;}

Dynamic SimpleRow_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleRow_obj > result = new SimpleRow_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *SimpleRow_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::coopy::Datum_obj)) return operator ::coopy::Datum_obj *();
	if (inType==typeid( ::coopy::Bag_obj)) return operator ::coopy::Bag_obj *();
	return super::__ToInterface(inType);
}

::coopy::View SimpleRow_obj::getItemView( ){
	HX_STACK_PUSH("SimpleRow::getItemView","coopy/SimpleRow.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	return ::coopy::SimpleView_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleRow_obj,getItemView,return )

::String SimpleRow_obj::toString( ){
	HX_STACK_PUSH("SimpleRow::toString","coopy/SimpleRow.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	::String x = HX_CSTRING("");		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->tab->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(36)
		while(((_g1 < _g))){
			HX_STACK_LINE(36)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(37)
			if (((i > (int)0))){
				HX_STACK_LINE(37)
				hx::AddEq(x,HX_CSTRING(" "));
			}
			HX_STACK_LINE(38)
			hx::AddEq(x,::Std_obj::string(this->getItem(i)));
		}
	}
	HX_STACK_LINE(40)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleRow_obj,toString,return )

::coopy::Table SimpleRow_obj::getTable( ){
	HX_STACK_PUSH("SimpleRow::getTable","coopy/SimpleRow.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleRow_obj,getTable,return )

Void SimpleRow_obj::setItem( int x,::coopy::Datum c){
{
		HX_STACK_PUSH("SimpleRow::setItem","coopy/SimpleRow.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(26)
		this->tab->setCell(x,this->row_id,c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleRow_obj,setItem,(void))

::coopy::Datum SimpleRow_obj::getItem( int x){
	HX_STACK_PUSH("SimpleRow::getItem","coopy/SimpleRow.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_LINE(22)
	return this->tab->getCell(x,this->row_id);
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleRow_obj,getItem,return )

int SimpleRow_obj::get_size( ){
	HX_STACK_PUSH("SimpleRow::get_size","coopy/SimpleRow.hx",18);
	HX_STACK_THIS(this);
	HX_STACK_LINE(18)
	return this->tab->__Field(HX_CSTRING("get_width"),true)();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleRow_obj,get_size,return )


SimpleRow_obj::SimpleRow_obj()
{
}

void SimpleRow_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleRow);
	HX_MARK_MEMBER_NAME(bag,"bag");
	HX_MARK_MEMBER_NAME(row_id,"row_id");
	HX_MARK_MEMBER_NAME(tab,"tab");
	HX_MARK_END_CLASS();
}

void SimpleRow_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bag,"bag");
	HX_VISIT_MEMBER_NAME(row_id,"row_id");
	HX_VISIT_MEMBER_NAME(tab,"tab");
}

Dynamic SimpleRow_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bag") ) { return bag; }
		if (HX_FIELD_EQ(inName,"tab") ) { return tab; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"row_id") ) { return row_id; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setItem") ) { return setItem_dyn(); }
		if (HX_FIELD_EQ(inName,"getItem") ) { return getItem_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"getTable") ) { return getTable_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getItemView") ) { return getItemView_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleRow_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"bag") ) { bag=inValue.Cast< ::coopy::Bag >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tab") ) { tab=inValue.Cast< ::coopy::Table >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"row_id") ) { row_id=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleRow_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("bag"));
	outFields->push(HX_CSTRING("row_id"));
	outFields->push(HX_CSTRING("tab"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getItemView"),
	HX_CSTRING("toString"),
	HX_CSTRING("getTable"),
	HX_CSTRING("setItem"),
	HX_CSTRING("getItem"),
	HX_CSTRING("get_size"),
	HX_CSTRING("bag"),
	HX_CSTRING("row_id"),
	HX_CSTRING("tab"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleRow_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleRow_obj::__mClass,"__mClass");
};

Class SimpleRow_obj::__mClass;

void SimpleRow_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.SimpleRow"), hx::TCanCast< SimpleRow_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SimpleRow_obj::__boot()
{
}

} // end namespace coopy
