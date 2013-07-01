#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_Index
#include <coopy/Index.h>
#endif
#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
#ifndef INCLUDED_coopy_Row
#include <coopy/Row.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace coopy{

Void Index_obj::__construct()
{
HX_STACK_PUSH("Index::new","coopy/Index.hx",15);
{
	HX_STACK_LINE(16)
	this->items = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(17)
	this->cols = Array_obj< int >::__new();
	HX_STACK_LINE(18)
	this->keys = Array_obj< ::String >::__new();
	HX_STACK_LINE(19)
	this->top_freq = (int)0;
	HX_STACK_LINE(20)
	this->height = (int)0;
}
;
	return null();
}

Index_obj::~Index_obj() { }

Dynamic Index_obj::__CreateEmpty() { return  new Index_obj; }
hx::ObjectPtr< Index_obj > Index_obj::__new()
{  hx::ObjectPtr< Index_obj > result = new Index_obj();
	result->__construct();
	return result;}

Dynamic Index_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Index_obj > result = new Index_obj();
	result->__construct();
	return result;}

::coopy::Table Index_obj::getTable( ){
	HX_STACK_PUSH("Index::getTable","coopy/Index.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(73)
	return this->indexed_table;
}


HX_DEFINE_DYNAMIC_FUNC0(Index_obj,getTable,return )

::String Index_obj::toKeyByContent( ::coopy::Row row){
	HX_STACK_PUSH("Index::toKeyByContent","coopy/Index.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(row,"row");
	HX_STACK_LINE(63)
	::String wide = HX_CSTRING("");		HX_STACK_VAR(wide,"wide");
	HX_STACK_LINE(64)
	{
		HX_STACK_LINE(64)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->cols->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		while(((_g1 < _g))){
			HX_STACK_LINE(64)
			int k = (_g1)++;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(65)
			::String txt = row->getRowString(this->cols->__get(k));		HX_STACK_VAR(txt,"txt");
			HX_STACK_LINE(66)
			if (((bool((bool((txt == HX_CSTRING(""))) || bool((txt == HX_CSTRING("null"))))) || bool((txt == HX_CSTRING("undefined")))))){
				HX_STACK_LINE(66)
				continue;
			}
			HX_STACK_LINE(67)
			if (((k > (int)0))){
				HX_STACK_LINE(67)
				hx::AddEq(wide,HX_CSTRING(" // "));
			}
			HX_STACK_LINE(68)
			hx::AddEq(wide,txt);
		}
	}
	HX_STACK_LINE(70)
	return wide;
}


HX_DEFINE_DYNAMIC_FUNC1(Index_obj,toKeyByContent,return )

::String Index_obj::toKey( ::coopy::Table t,int i){
	HX_STACK_PUSH("Index::toKey","coopy/Index.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(i,"i");
	HX_STACK_LINE(50)
	::String wide = HX_CSTRING("");		HX_STACK_VAR(wide,"wide");
	HX_STACK_LINE(51)
	if (((this->v == null()))){
		HX_STACK_LINE(51)
		this->v = t->getCellView();
	}
	HX_STACK_LINE(52)
	{
		HX_STACK_LINE(52)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->cols->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(52)
		while(((_g1 < _g))){
			HX_STACK_LINE(52)
			int k = (_g1)++;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(53)
			Dynamic d = t->getCell(this->cols->__get(k),i);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(54)
			::String txt = this->v->toString(d);		HX_STACK_VAR(txt,"txt");
			HX_STACK_LINE(55)
			if (((bool((bool((txt == HX_CSTRING(""))) || bool((txt == HX_CSTRING("null"))))) || bool((txt == HX_CSTRING("undefined")))))){
				HX_STACK_LINE(55)
				continue;
			}
			HX_STACK_LINE(56)
			if (((k > (int)0))){
				HX_STACK_LINE(56)
				hx::AddEq(wide,HX_CSTRING(" // "));
			}
			HX_STACK_LINE(57)
			hx::AddEq(wide,txt);
		}
	}
	HX_STACK_LINE(59)
	return wide;
}


HX_DEFINE_DYNAMIC_FUNC2(Index_obj,toKey,return )

Void Index_obj::indexTable( ::coopy::Table t){
{
		HX_STACK_PUSH("Index::indexTable","coopy/Index.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(t,"t");
		HX_STACK_LINE(28)
		this->indexed_table = t;
		HX_STACK_LINE(29)
		{
			HX_STACK_LINE(29)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = t->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(29)
			while(((_g1 < _g))){
				HX_STACK_LINE(29)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(30)
				::String key;		HX_STACK_VAR(key,"key");
				HX_STACK_LINE(31)
				if (((this->keys->length > i))){
					HX_STACK_LINE(31)
					key = this->keys->__get(i);
				}
				else{
					HX_STACK_LINE(34)
					key = this->toKey(t,i);
					HX_STACK_LINE(35)
					this->keys->push(key);
				}
				HX_STACK_LINE(37)
				::coopy::IndexItem item = this->items->get(key);		HX_STACK_VAR(item,"item");
				HX_STACK_LINE(38)
				if (((item == null()))){
					HX_STACK_LINE(39)
					item = ::coopy::IndexItem_obj::__new();
					HX_STACK_LINE(40)
					this->items->set(key,item);
				}
				HX_STACK_LINE(42)
				int ct = item->add(i);		HX_STACK_VAR(ct,"ct");
				HX_STACK_LINE(43)
				if (((ct > this->top_freq))){
					HX_STACK_LINE(43)
					this->top_freq = ct;
				}
			}
		}
		HX_STACK_LINE(45)
		this->height = t->__Field(HX_CSTRING("get_height"),true)();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Index_obj,indexTable,(void))

Void Index_obj::addColumn( int i){
{
		HX_STACK_PUSH("Index::addColumn","coopy/Index.hx",23);
		HX_STACK_THIS(this);
		HX_STACK_ARG(i,"i");
		HX_STACK_LINE(23)
		this->cols->push(i);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Index_obj,addColumn,(void))


Index_obj::Index_obj()
{
}

void Index_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Index);
	HX_MARK_MEMBER_NAME(indexed_table,"indexed_table");
	HX_MARK_MEMBER_NAME(v,"v");
	HX_MARK_MEMBER_NAME(cols,"cols");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(top_freq,"top_freq");
	HX_MARK_MEMBER_NAME(keys,"keys");
	HX_MARK_MEMBER_NAME(items,"items");
	HX_MARK_END_CLASS();
}

void Index_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(indexed_table,"indexed_table");
	HX_VISIT_MEMBER_NAME(v,"v");
	HX_VISIT_MEMBER_NAME(cols,"cols");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(top_freq,"top_freq");
	HX_VISIT_MEMBER_NAME(keys,"keys");
	HX_VISIT_MEMBER_NAME(items,"items");
}

Dynamic Index_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"v") ) { return v; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cols") ) { return cols; }
		if (HX_FIELD_EQ(inName,"keys") ) { return keys; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toKey") ) { return toKey_dyn(); }
		if (HX_FIELD_EQ(inName,"items") ) { return items; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getTable") ) { return getTable_dyn(); }
		if (HX_FIELD_EQ(inName,"top_freq") ) { return top_freq; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addColumn") ) { return addColumn_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"indexTable") ) { return indexTable_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"indexed_table") ) { return indexed_table; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"toKeyByContent") ) { return toKeyByContent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Index_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"v") ) { v=inValue.Cast< ::coopy::View >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cols") ) { cols=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keys") ) { keys=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"items") ) { items=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"top_freq") ) { top_freq=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"indexed_table") ) { indexed_table=inValue.Cast< ::coopy::Table >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Index_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("indexed_table"));
	outFields->push(HX_CSTRING("v"));
	outFields->push(HX_CSTRING("cols"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("top_freq"));
	outFields->push(HX_CSTRING("keys"));
	outFields->push(HX_CSTRING("items"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTable"),
	HX_CSTRING("toKeyByContent"),
	HX_CSTRING("toKey"),
	HX_CSTRING("indexTable"),
	HX_CSTRING("addColumn"),
	HX_CSTRING("indexed_table"),
	HX_CSTRING("v"),
	HX_CSTRING("cols"),
	HX_CSTRING("height"),
	HX_CSTRING("top_freq"),
	HX_CSTRING("keys"),
	HX_CSTRING("items"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Index_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Index_obj::__mClass,"__mClass");
};

Class Index_obj::__mClass;

void Index_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Index"), hx::TCanCast< Index_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Index_obj::__boot()
{
}

} // end namespace coopy
