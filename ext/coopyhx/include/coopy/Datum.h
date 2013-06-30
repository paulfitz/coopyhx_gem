#ifndef INCLUDED_coopy_Datum
#define INCLUDED_coopy_Datum

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Datum)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  Datum_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef Datum_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual ::String toString( )=0;
		Dynamic toString_dyn();
};

#define DELEGATE_coopy_Datum \
virtual ::String toString( ) { return mDelegate->toString();}  \
virtual Dynamic toString_dyn() { return mDelegate->toString_dyn();}  \


template<typename IMPL>
class Datum_delegate_ : public Datum_obj
{
	protected:
		IMPL *mDelegate;
	public:
		Datum_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_coopy_Datum
};

} // end namespace coopy

#endif /* INCLUDED_coopy_Datum */ 
