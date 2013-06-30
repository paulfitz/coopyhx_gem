#ifndef INCLUDED_coopy_SimpleView
#define INCLUDED_coopy_SimpleView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <coopy/View.h>
HX_DECLARE_CLASS1(coopy,Bag)
HX_DECLARE_CLASS1(coopy,Datum)
HX_DECLARE_CLASS1(coopy,SimpleView)
HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,View)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  SimpleView_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleView_obj OBJ_;
		SimpleView_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SimpleView_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SimpleView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		// hxcpp output massaged for SWIG //SWIGFIX
		inline ::hx::ObjectPtr< ::coopy::View_obj> asView() //SWIGFIX
			{ return ::hx::ObjectPtr< ::coopy::View_obj>(this); } //SWIGFIX
#ifndef SWIG //SWIGFIX
		inline operator ::coopy::View_obj *()
			{ return new ::coopy::View_delegate_< SimpleView_obj >(this); }
#endif //SWIGFIX
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SimpleView"); }

		virtual ::coopy::Datum toDatum( ::String str);
		Dynamic toDatum_dyn();

		virtual bool equals( ::coopy::Datum d1,::coopy::Datum d2);
		Dynamic equals_dyn();

		virtual bool hasStructure( ::coopy::Datum d);
		Dynamic hasStructure_dyn();

		virtual ::coopy::Table getTable( ::coopy::Datum d);
		Dynamic getTable_dyn();

		virtual ::coopy::Bag getBag( ::coopy::Datum d);
		Dynamic getBag_dyn();

		virtual ::String toString( ::coopy::Datum d);
		Dynamic toString_dyn();

};

} // end namespace coopy

#endif /* INCLUDED_coopy_SimpleView */ 
