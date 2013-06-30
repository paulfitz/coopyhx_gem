#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_coopy_Change
#include <coopy/Change.h>
#endif
#ifndef INCLUDED_coopy_ChangeType
#include <coopy/ChangeType.h>
#endif
#ifndef INCLUDED_coopy_ViewedDatum
#include <coopy/ViewedDatum.h>
#endif
namespace coopy{

Void Change_obj::__construct(::String txt)
{
HX_STACK_PUSH("Change::new","coopy/Change.hx",14);
{
	HX_STACK_LINE(14)
	if (((txt != null()))){
		HX_STACK_LINE(16)
		this->mode = ::coopy::ChangeType_obj::NOTE_CHANGE;
		HX_STACK_LINE(17)
		this->change = txt;
	}
	else{
		HX_STACK_LINE(18)
		this->mode = ::coopy::ChangeType_obj::NO_CHANGE;
	}
}
;
	return null();
}

Change_obj::~Change_obj() { }

Dynamic Change_obj::__CreateEmpty() { return  new Change_obj; }
hx::ObjectPtr< Change_obj > Change_obj::__new(::String txt)
{  hx::ObjectPtr< Change_obj > result = new Change_obj();
	result->__construct(txt);
	return result;}

Dynamic Change_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Change_obj > result = new Change_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Change_obj::toString( ){
	HX_STACK_PUSH("Change::toString","coopy/Change.hx",23);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::String Block( ::coopy::Change_obj *__this){
			HX_STACK_PUSH("*::closure","coopy/Change.hx",24);
			{
				HX_STACK_LINE(24)
				::coopy::Change _g = __this;		HX_STACK_VAR(_g,"_g");
				struct _Function_2_1{
					inline static ::String Block( ::coopy::Change &_g,::coopy::Change_obj *__this){
						HX_STACK_PUSH("*::closure","coopy/Change.hx",24);
						{
							HX_STACK_LINE(24)
							{
								::coopy::ChangeType _switch_1 = (_g->mode);
								switch((_switch_1)->GetIndex()){
									case 0: {
										HX_STACK_LINE(25)
										return HX_CSTRING("no change");
									}
									;break;
									case 2: {
										HX_STACK_LINE(26)
										return (((HX_CSTRING("local change: ") + ::Std_obj::string(__this->remote)) + HX_CSTRING(" -> ")) + ::Std_obj::string(__this->local));
									}
									;break;
									case 1: {
										HX_STACK_LINE(27)
										return (((HX_CSTRING("remote change: ") + ::Std_obj::string(__this->local)) + HX_CSTRING(" -> ")) + ::Std_obj::string(__this->remote));
									}
									;break;
									case 3: {
										HX_STACK_LINE(28)
										return (((((HX_CSTRING("conflicting change: ") + ::Std_obj::string(__this->parent)) + HX_CSTRING(" -> ")) + ::Std_obj::string(__this->local)) + HX_CSTRING(" / ")) + ::Std_obj::string(__this->remote));
									}
									;break;
									case 4: {
										HX_STACK_LINE(29)
										return (((((HX_CSTRING("same change: ") + ::Std_obj::string(__this->parent)) + HX_CSTRING(" -> ")) + ::Std_obj::string(__this->local)) + HX_CSTRING(" / ")) + ::Std_obj::string(__this->remote));
									}
									;break;
									case 5: {
										HX_STACK_LINE(30)
										return __this->change;
									}
									;break;
								}
							}
						}
						return null();
					}
				};
				HX_STACK_LINE(24)
				return _Function_2_1::Block(_g,__this);
			}
			return null();
		}
	};
	HX_STACK_LINE(23)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Change_obj,toString,return )


Change_obj::Change_obj()
{
}

void Change_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Change);
	HX_MARK_MEMBER_NAME(mode,"mode");
	HX_MARK_MEMBER_NAME(remote,"remote");
	HX_MARK_MEMBER_NAME(local,"local");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(change,"change");
	HX_MARK_END_CLASS();
}

void Change_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mode,"mode");
	HX_VISIT_MEMBER_NAME(remote,"remote");
	HX_VISIT_MEMBER_NAME(local,"local");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(change,"change");
}

Dynamic Change_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { return mode; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"local") ) { return local; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remote") ) { return remote; }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"change") ) { return change; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Change_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mode") ) { mode=inValue.Cast< ::coopy::ChangeType >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"local") ) { local=inValue.Cast< ::coopy::ViewedDatum >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remote") ) { remote=inValue.Cast< ::coopy::ViewedDatum >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::coopy::ViewedDatum >(); return inValue; }
		if (HX_FIELD_EQ(inName,"change") ) { change=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Change_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mode"));
	outFields->push(HX_CSTRING("remote"));
	outFields->push(HX_CSTRING("local"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("change"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("mode"),
	HX_CSTRING("remote"),
	HX_CSTRING("local"),
	HX_CSTRING("parent"),
	HX_CSTRING("change"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Change_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Change_obj::__mClass,"__mClass");
};

Class Change_obj::__mClass;

void Change_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Change"), hx::TCanCast< Change_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Change_obj::__boot()
{
}

} // end namespace coopy
