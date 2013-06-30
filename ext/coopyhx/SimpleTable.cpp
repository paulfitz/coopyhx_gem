#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
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
#ifndef INCLUDED_coopy_SimpleRow
#include <coopy/SimpleRow.h>
#endif
#ifndef INCLUDED_coopy_SimpleTable
#include <coopy/SimpleTable.h>
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
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
namespace coopy{

Void SimpleTable_obj::__construct(int w,int h)
{
HX_STACK_PUSH("SimpleTable::new","coopy/SimpleTable.hx",13);
{
	HX_STACK_LINE(14)
	this->data = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(15)
	this->w = w;
	HX_STACK_LINE(16)
	this->h = h;
	HX_STACK_LINE(17)
	this->bag = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

SimpleTable_obj::~SimpleTable_obj() { }

Dynamic SimpleTable_obj::__CreateEmpty() { return  new SimpleTable_obj; }
hx::ObjectPtr< SimpleTable_obj > SimpleTable_obj::__new(int w,int h)
{  hx::ObjectPtr< SimpleTable_obj > result = new SimpleTable_obj();
	result->__construct(w,h);
	return result;}

Dynamic SimpleTable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleTable_obj > result = new SimpleTable_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *SimpleTable_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::coopy::Datum_obj)) return operator ::coopy::Datum_obj *();
	if (inType==typeid( ::coopy::Bag_obj)) return operator ::coopy::Bag_obj *();
	if (inType==typeid( ::coopy::Table_obj)) return operator ::coopy::Table_obj *();
	return super::__ToInterface(inType);
}

bool SimpleTable_obj::trimBlank( ){
	HX_STACK_PUSH("SimpleTable::trimBlank","coopy/SimpleTable.hx",146);
	HX_STACK_THIS(this);
	HX_STACK_LINE(147)
	::coopy::View view = this->getCellView();		HX_STACK_VAR(view,"view");
	HX_STACK_LINE(148)
	::coopy::Datum space = view->toDatum(HX_CSTRING(""));		HX_STACK_VAR(space,"space");
	HX_STACK_LINE(149)
	bool more = true;		HX_STACK_VAR(more,"more");
	HX_STACK_LINE(150)
	while((more)){
		HX_STACK_LINE(151)
		if (((this->h == (int)0))){
			HX_STACK_LINE(151)
			return true;
		}
		HX_STACK_LINE(152)
		{
			HX_STACK_LINE(152)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->get_width();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(152)
			while(((_g1 < _g))){
				HX_STACK_LINE(152)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(153)
				::coopy::Datum c = this->getCell(i,(this->h - (int)1));		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(154)
				if ((!(((bool(view->equals(c,space)) || bool((c == null()))))))){
					HX_STACK_LINE(155)
					more = false;
					HX_STACK_LINE(156)
					break;
				}
			}
		}
		HX_STACK_LINE(159)
		if ((more)){
			HX_STACK_LINE(159)
			(this->h)--;
		}
	}
	HX_STACK_LINE(161)
	more = true;
	HX_STACK_LINE(162)
	int nw = this->w;		HX_STACK_VAR(nw,"nw");
	HX_STACK_LINE(163)
	while((more)){
		HX_STACK_LINE(164)
		if (((this->w == (int)0))){
			HX_STACK_LINE(164)
			break;
		}
		HX_STACK_LINE(165)
		{
			HX_STACK_LINE(165)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(165)
			while(((_g < (int)1))){
				HX_STACK_LINE(165)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(166)
				::coopy::Datum c = this->getCell((nw - (int)1),i);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(167)
				if ((!(((bool(view->equals(c,space)) || bool((c == null()))))))){
					HX_STACK_LINE(168)
					more = false;
					HX_STACK_LINE(169)
					break;
				}
			}
		}
		HX_STACK_LINE(172)
		if ((more)){
			HX_STACK_LINE(172)
			(nw)--;
		}
	}
	HX_STACK_LINE(174)
	if (((nw == this->w))){
		HX_STACK_LINE(174)
		return true;
	}
	HX_STACK_LINE(175)
	::haxe::ds::IntMap data2 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(data2,"data2");
	HX_STACK_LINE(176)
	{
		HX_STACK_LINE(176)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(176)
		while(((_g < nw))){
			HX_STACK_LINE(176)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(177)
			{
				HX_STACK_LINE(177)
				int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
				int _g1 = this->h;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(177)
				while(((_g2 < _g1))){
					HX_STACK_LINE(177)
					int r = (_g2)++;		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(178)
					int idx = ((r * this->w) + i);		HX_STACK_VAR(idx,"idx");
					HX_STACK_LINE(179)
					if ((this->data->exists(idx))){
						HX_STACK_LINE(179)
						data2->set(((r * nw) + i),this->data->get(idx));
					}
				}
			}
		}
	}
	HX_STACK_LINE(184)
	this->w = nw;
	HX_STACK_LINE(185)
	this->data = data2;
	HX_STACK_LINE(186)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,trimBlank,return )

bool SimpleTable_obj::insertOrDeleteColumns( Array< int > fate,int wfate){
	HX_STACK_PUSH("SimpleTable::insertOrDeleteColumns","coopy/SimpleTable.hx",128);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fate,"fate");
	HX_STACK_ARG(wfate,"wfate");
	HX_STACK_LINE(129)
	::haxe::ds::IntMap data2 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(data2,"data2");
	HX_STACK_LINE(130)
	{
		HX_STACK_LINE(130)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = fate->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(130)
		while(((_g1 < _g))){
			HX_STACK_LINE(130)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(131)
			int j = fate->__get(i);		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(132)
			if (((j != (int)-1))){
				HX_STACK_LINE(133)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = this->h;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(133)
				while(((_g3 < _g2))){
					HX_STACK_LINE(133)
					int r = (_g3)++;		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(134)
					int idx = ((r * this->w) + i);		HX_STACK_VAR(idx,"idx");
					HX_STACK_LINE(135)
					if ((this->data->exists(idx))){
						HX_STACK_LINE(135)
						data2->set(((r * wfate) + j),this->data->get(idx));
					}
				}
			}
		}
	}
	HX_STACK_LINE(141)
	this->w = wfate;
	HX_STACK_LINE(142)
	this->data = data2;
	HX_STACK_LINE(143)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleTable_obj,insertOrDeleteColumns,return )

bool SimpleTable_obj::insertOrDeleteRows( Array< int > fate,int hfate){
	HX_STACK_PUSH("SimpleTable::insertOrDeleteRows","coopy/SimpleTable.hx",110);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fate,"fate");
	HX_STACK_ARG(hfate,"hfate");
	HX_STACK_LINE(111)
	::haxe::ds::IntMap data2 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(data2,"data2");
	HX_STACK_LINE(112)
	{
		HX_STACK_LINE(112)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = fate->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(112)
		while(((_g1 < _g))){
			HX_STACK_LINE(112)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(113)
			int j = fate->__get(i);		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(114)
			if (((j != (int)-1))){
				HX_STACK_LINE(115)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = this->w;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(115)
				while(((_g3 < _g2))){
					HX_STACK_LINE(115)
					int c = (_g3)++;		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(116)
					int idx = ((i * this->w) + c);		HX_STACK_VAR(idx,"idx");
					HX_STACK_LINE(117)
					if ((this->data->exists(idx))){
						HX_STACK_LINE(117)
						data2->set(((j * this->w) + c),this->data->get(idx));
					}
				}
			}
		}
	}
	HX_STACK_LINE(123)
	this->h = hfate;
	HX_STACK_LINE(124)
	this->data = data2;
	HX_STACK_LINE(125)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleTable_obj,insertOrDeleteRows,return )

Void SimpleTable_obj::clear( ){
{
		HX_STACK_PUSH("SimpleTable::clear","coopy/SimpleTable.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_LINE(86)
		this->data = ::haxe::ds::IntMap_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,clear,(void))

bool SimpleTable_obj::resize( int w,int h){
	HX_STACK_PUSH("SimpleTable::resize","coopy/SimpleTable.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_ARG(w,"w");
	HX_STACK_ARG(h,"h");
	HX_STACK_LINE(81)
	this->w = w;
	HX_STACK_LINE(82)
	this->h = h;
	HX_STACK_LINE(83)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleTable_obj,resize,return )

bool SimpleTable_obj::isResizable( ){
	HX_STACK_PUSH("SimpleTable::isResizable","coopy/SimpleTable.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_LINE(76)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,isResizable,return )

::coopy::View SimpleTable_obj::getItemView( ){
	HX_STACK_PUSH("SimpleTable::getItemView","coopy/SimpleTable.hx",72);
	HX_STACK_THIS(this);
	HX_STACK_LINE(72)
	return ::coopy::BagView_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,getItemView,return )

::coopy::View SimpleTable_obj::getCellView( ){
	HX_STACK_PUSH("SimpleTable::getCellView","coopy/SimpleTable.hx",68);
	HX_STACK_THIS(this);
	HX_STACK_LINE(68)
	return ::coopy::SimpleView_obj::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,getCellView,return )

::String SimpleTable_obj::toString( ){
	HX_STACK_PUSH("SimpleTable::toString","coopy/SimpleTable.hx",52);
	HX_STACK_THIS(this);
	HX_STACK_LINE(52)
	return ::coopy::SimpleTable_obj::tableToString(hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,toString,return )

::coopy::Datum SimpleTable_obj::getItem( int y){
	HX_STACK_PUSH("SimpleTable::getItem","coopy/SimpleTable.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(48)
	return ::coopy::SimpleRow_obj::__new(hx::ObjectPtr<OBJ_>(this),y);
}


HX_DEFINE_DYNAMIC_FUNC1(SimpleTable_obj,getItem,return )

Void SimpleTable_obj::setCell( int x,int y,::coopy::Datum c){
{
		HX_STACK_PUSH("SimpleTable::setCell","coopy/SimpleTable.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(44)
		this->data->set((x + (y * this->w)),c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(SimpleTable_obj,setCell,(void))

::coopy::Datum SimpleTable_obj::getCell( int x,int y){
	HX_STACK_PUSH("SimpleTable::getCell","coopy/SimpleTable.hx",40);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(40)
	return this->data->get((x + (y * this->w)));
}


HX_DEFINE_DYNAMIC_FUNC2(SimpleTable_obj,getCell,return )

int SimpleTable_obj::get_size( ){
	HX_STACK_PUSH("SimpleTable::get_size","coopy/SimpleTable.hx",36);
	HX_STACK_THIS(this);
	HX_STACK_LINE(36)
	return this->h;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,get_size,return )

int SimpleTable_obj::get_height( ){
	HX_STACK_PUSH("SimpleTable::get_height","coopy/SimpleTable.hx",32);
	HX_STACK_THIS(this);
	HX_STACK_LINE(32)
	return this->h;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,get_height,return )

int SimpleTable_obj::get_width( ){
	HX_STACK_PUSH("SimpleTable::get_width","coopy/SimpleTable.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_LINE(28)
	return this->w;
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,get_width,return )

::coopy::Table SimpleTable_obj::getTable( ){
	HX_STACK_PUSH("SimpleTable::getTable","coopy/SimpleTable.hx",20);
	HX_STACK_THIS(this);
	HX_STACK_LINE(20)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(SimpleTable_obj,getTable,return )

::String SimpleTable_obj::tableToString( ::coopy::Table tab){
	HX_STACK_PUSH("SimpleTable::tableToString","coopy/SimpleTable.hx",56);
	HX_STACK_ARG(tab,"tab");
	HX_STACK_LINE(57)
	::String x = HX_CSTRING("");		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(58)
	{
		HX_STACK_LINE(58)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = tab->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		while(((_g1 < _g))){
			HX_STACK_LINE(58)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(59)
			{
				HX_STACK_LINE(59)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				int _g2 = tab->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(59)
				while(((_g3 < _g2))){
					HX_STACK_LINE(59)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(60)
					if (((j > (int)0))){
						HX_STACK_LINE(60)
						hx::AddEq(x,HX_CSTRING(" "));
					}
					HX_STACK_LINE(61)
					hx::AddEq(x,::Std_obj::string(tab->getCell(j,i)));
				}
			}
			HX_STACK_LINE(63)
			hx::AddEq(x,HX_CSTRING("\n"));
		}
	}
	HX_STACK_LINE(65)
	return x;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleTable_obj,tableToString,return )


SimpleTable_obj::SimpleTable_obj()
{
}

void SimpleTable_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleTable);
	HX_MARK_MEMBER_NAME(bag,"bag");
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_END_CLASS();
}

void SimpleTable_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bag,"bag");
	HX_VISIT_MEMBER_NAME(h,"h");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(data,"data");
}

Dynamic SimpleTable_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		if (HX_FIELD_EQ(inName,"w") ) { return w; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"bag") ) { return bag; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getItem") ) { return getItem_dyn(); }
		if (HX_FIELD_EQ(inName,"setCell") ) { return setCell_dyn(); }
		if (HX_FIELD_EQ(inName,"getCell") ) { return getCell_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"getTable") ) { return getTable_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"trimBlank") ) { return trimBlank_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isResizable") ) { return isResizable_dyn(); }
		if (HX_FIELD_EQ(inName,"getItemView") ) { return getItemView_dyn(); }
		if (HX_FIELD_EQ(inName,"getCellView") ) { return getCellView_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"tableToString") ) { return tableToString_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"insertOrDeleteRows") ) { return insertOrDeleteRows_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"insertOrDeleteColumns") ) { return insertOrDeleteColumns_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleTable_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"bag") ) { bag=inValue.Cast< ::coopy::Bag >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleTable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("bag"));
	outFields->push(HX_CSTRING("h"));
	outFields->push(HX_CSTRING("w"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("tableToString"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("trimBlank"),
	HX_CSTRING("insertOrDeleteColumns"),
	HX_CSTRING("insertOrDeleteRows"),
	HX_CSTRING("clear"),
	HX_CSTRING("resize"),
	HX_CSTRING("isResizable"),
	HX_CSTRING("getItemView"),
	HX_CSTRING("getCellView"),
	HX_CSTRING("toString"),
	HX_CSTRING("getItem"),
	HX_CSTRING("setCell"),
	HX_CSTRING("getCell"),
	HX_CSTRING("get_size"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("getTable"),
	HX_CSTRING("bag"),
	HX_CSTRING("h"),
	HX_CSTRING("w"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleTable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleTable_obj::__mClass,"__mClass");
};

Class SimpleTable_obj::__mClass;

void SimpleTable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.SimpleTable"), hx::TCanCast< SimpleTable_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SimpleTable_obj::__boot()
{
}

} // end namespace coopy
