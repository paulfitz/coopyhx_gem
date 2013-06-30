#ifndef INCLUDED_coopy_Unit
#define INCLUDED_coopy_Unit

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(coopy,Unit)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  Unit_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Unit_obj OBJ_;
		Unit_obj();
		Void __construct(int l,int r,hx::Null< int >  __o_p);

	public:
		static hx::ObjectPtr< Unit_obj > __new(int l,int r,hx::Null< int >  __o_p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Unit_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Unit"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual int lp( );
		Dynamic lp_dyn();

		int p;
		int r;
		int l;
		static ::String describe( int i);
		static Dynamic describe_dyn();

};

} // end namespace coopy

#endif /* INCLUDED_coopy_Unit */ 
