#include <hxcpp.h>

#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
namespace coopy{

HX_DEFINE_DYNAMIC_FUNC0(Datum_obj,toString,return )


static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Datum_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Datum_obj::__mClass,"__mClass");
};

Class Datum_obj::__mClass;

void Datum_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Datum"), hx::TCanCast< Datum_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Datum_obj::__boot()
{
}

} // end namespace coopy
