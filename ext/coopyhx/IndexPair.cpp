#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_CrossMatch
#include <coopy/CrossMatch.h>
#endif
#ifndef INCLUDED_coopy_Index
#include <coopy/Index.h>
#endif
#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
#ifndef INCLUDED_coopy_IndexPair
#include <coopy/IndexPair.h>
#endif
#ifndef INCLUDED_coopy_Row
#include <coopy/Row.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace coopy{

Void IndexPair_obj::__construct()
{
HX_STACK_PUSH("IndexPair::new","coopy/IndexPair.hx",10);
{
	HX_STACK_LINE(11)
	this->ia = ::coopy::Index_obj::__new();
	HX_STACK_LINE(12)
	this->ib = ::coopy::Index_obj::__new();
	HX_STACK_LINE(13)
	this->quality = (int)0;
}
;
	return null();
}

IndexPair_obj::~IndexPair_obj() { }

Dynamic IndexPair_obj::__CreateEmpty() { return  new IndexPair_obj; }
hx::ObjectPtr< IndexPair_obj > IndexPair_obj::__new()
{  hx::ObjectPtr< IndexPair_obj > result = new IndexPair_obj();
	result->__construct();
	return result;}

Dynamic IndexPair_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IndexPair_obj > result = new IndexPair_obj();
	result->__construct();
	return result;}

Float IndexPair_obj::getQuality( ){
	HX_STACK_PUSH("IndexPair::getQuality","coopy/IndexPair.hx",74);
	HX_STACK_THIS(this);
	HX_STACK_LINE(74)
	return this->quality;
}


HX_DEFINE_DYNAMIC_FUNC0(IndexPair_obj,getQuality,return )

int IndexPair_obj::getTopFreq( ){
	HX_STACK_PUSH("IndexPair::getTopFreq","coopy/IndexPair.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	if (((this->ib->top_freq > this->ia->top_freq))){
		HX_STACK_LINE(70)
		return this->ib->top_freq;
	}
	HX_STACK_LINE(71)
	return this->ia->top_freq;
}


HX_DEFINE_DYNAMIC_FUNC0(IndexPair_obj,getTopFreq,return )

::coopy::CrossMatch IndexPair_obj::queryLocal( int row){
	HX_STACK_PUSH("IndexPair::queryLocal","coopy/IndexPair.hx",64);
	HX_STACK_THIS(this);
	HX_STACK_ARG(row,"row");
	HX_STACK_LINE(65)
	::String ka = this->ia->toKey(this->ia->getTable(),row);		HX_STACK_VAR(ka,"ka");
	HX_STACK_LINE(66)
	return this->queryByKey(ka);
}


HX_DEFINE_DYNAMIC_FUNC1(IndexPair_obj,queryLocal,return )

::coopy::CrossMatch IndexPair_obj::queryByContent( ::coopy::Row row){
	HX_STACK_PUSH("IndexPair::queryByContent","coopy/IndexPair.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_ARG(row,"row");
	HX_STACK_LINE(59)
	::coopy::CrossMatch result = ::coopy::CrossMatch_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(60)
	::String ka = this->ia->toKeyByContent(row);		HX_STACK_VAR(ka,"ka");
	HX_STACK_LINE(61)
	return this->queryByKey(ka);
}


HX_DEFINE_DYNAMIC_FUNC1(IndexPair_obj,queryByContent,return )

::coopy::CrossMatch IndexPair_obj::queryByKey( ::String ka){
	HX_STACK_PUSH("IndexPair::queryByKey","coopy/IndexPair.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ka,"ka");
	HX_STACK_LINE(47)
	::coopy::CrossMatch result = ::coopy::CrossMatch_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(48)
	result->item_a = this->ia->items->get(ka);
	HX_STACK_LINE(49)
	result->item_b = this->ib->items->get(ka);
	HX_STACK_LINE(50)
	result->spot_a = result->spot_b = (int)0;
	HX_STACK_LINE(51)
	if (((ka != HX_CSTRING("")))){
		HX_STACK_LINE(52)
		if (((result->item_a != null()))){
			HX_STACK_LINE(52)
			result->spot_a = result->item_a->lst->length;
		}
		HX_STACK_LINE(53)
		if (((result->item_b != null()))){
			HX_STACK_LINE(53)
			result->spot_b = result->item_b->lst->length;
		}
	}
	HX_STACK_LINE(55)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(IndexPair_obj,queryByKey,return )

Void IndexPair_obj::indexTables( ::coopy::Table a,::coopy::Table b){
{
		HX_STACK_PUSH("IndexPair::indexTables","coopy/IndexPair.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(b,"b");
		HX_STACK_LINE(27)
		this->ia->indexTable(a);
		HX_STACK_LINE(28)
		this->ib->indexTable(b);
		HX_STACK_LINE(32)
		int good = (int)0;		HX_STACK_VAR(good,"good");
		HX_STACK_LINE(33)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->ia->items->keys());  __it->hasNext(); ){
			::String key = __it->next();
			{
				HX_STACK_LINE(34)
				::coopy::IndexItem item_a = this->ia->items->get(key);		HX_STACK_VAR(item_a,"item_a");
				HX_STACK_LINE(35)
				int spot_a = item_a->lst->length;		HX_STACK_VAR(spot_a,"spot_a");
				HX_STACK_LINE(36)
				::coopy::IndexItem item_b = this->ib->items->get(key);		HX_STACK_VAR(item_b,"item_b");
				HX_STACK_LINE(37)
				int spot_b = (int)0;		HX_STACK_VAR(spot_b,"spot_b");
				HX_STACK_LINE(38)
				if (((item_b != null()))){
					HX_STACK_LINE(38)
					spot_b = item_b->lst->length;
				}
				HX_STACK_LINE(39)
				if (((bool((spot_a == (int)1)) && bool((spot_b == (int)1))))){
					HX_STACK_LINE(39)
					(good)++;
				}
			}
;
		}
		HX_STACK_LINE(43)
		this->quality = (Float(good) / Float(::Math_obj::max(1.0,a->__Field(HX_CSTRING("get_height"),true)())));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IndexPair_obj,indexTables,(void))

Void IndexPair_obj::addColumns( int ca,int cb){
{
		HX_STACK_PUSH("IndexPair::addColumns","coopy/IndexPair.hx",21);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ca,"ca");
		HX_STACK_ARG(cb,"cb");
		HX_STACK_LINE(22)
		this->ia->addColumn(ca);
		HX_STACK_LINE(23)
		this->ib->addColumn(cb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(IndexPair_obj,addColumns,(void))

Void IndexPair_obj::addColumn( int i){
{
		HX_STACK_PUSH("IndexPair::addColumn","coopy/IndexPair.hx",16);
		HX_STACK_THIS(this);
		HX_STACK_ARG(i,"i");
		HX_STACK_LINE(17)
		this->ia->addColumn(i);
		HX_STACK_LINE(18)
		this->ib->addColumn(i);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(IndexPair_obj,addColumn,(void))


IndexPair_obj::IndexPair_obj()
{
}

void IndexPair_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(IndexPair);
	HX_MARK_MEMBER_NAME(quality,"quality");
	HX_MARK_MEMBER_NAME(ib,"ib");
	HX_MARK_MEMBER_NAME(ia,"ia");
	HX_MARK_END_CLASS();
}

void IndexPair_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(quality,"quality");
	HX_VISIT_MEMBER_NAME(ib,"ib");
	HX_VISIT_MEMBER_NAME(ia,"ia");
}

Dynamic IndexPair_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ib") ) { return ib; }
		if (HX_FIELD_EQ(inName,"ia") ) { return ia; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { return quality; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addColumn") ) { return addColumn_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getQuality") ) { return getQuality_dyn(); }
		if (HX_FIELD_EQ(inName,"getTopFreq") ) { return getTopFreq_dyn(); }
		if (HX_FIELD_EQ(inName,"queryLocal") ) { return queryLocal_dyn(); }
		if (HX_FIELD_EQ(inName,"queryByKey") ) { return queryByKey_dyn(); }
		if (HX_FIELD_EQ(inName,"addColumns") ) { return addColumns_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"indexTables") ) { return indexTables_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"queryByContent") ) { return queryByContent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IndexPair_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ib") ) { ib=inValue.Cast< ::coopy::Index >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ia") ) { ia=inValue.Cast< ::coopy::Index >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"quality") ) { quality=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IndexPair_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("quality"));
	outFields->push(HX_CSTRING("ib"));
	outFields->push(HX_CSTRING("ia"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getQuality"),
	HX_CSTRING("getTopFreq"),
	HX_CSTRING("queryLocal"),
	HX_CSTRING("queryByContent"),
	HX_CSTRING("queryByKey"),
	HX_CSTRING("indexTables"),
	HX_CSTRING("addColumns"),
	HX_CSTRING("addColumn"),
	HX_CSTRING("quality"),
	HX_CSTRING("ib"),
	HX_CSTRING("ia"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IndexPair_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IndexPair_obj::__mClass,"__mClass");
};

Class IndexPair_obj::__mClass;

void IndexPair_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.IndexPair"), hx::TCanCast< IndexPair_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IndexPair_obj::__boot()
{
}

} // end namespace coopy
