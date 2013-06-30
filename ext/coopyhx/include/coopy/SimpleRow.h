#ifndef INCLUDED_coopy_SimpleRow
#define INCLUDED_coopy_SimpleRow

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <coopy/Datum.h>
#include <coopy/Bag.h>
HX_DECLARE_CLASS1(coopy,Bag)
HX_DECLARE_CLASS1(coopy,Datum)
HX_DECLARE_CLASS1(coopy,SimpleRow)
HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,View)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  SimpleRow_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleRow_obj OBJ_;
		SimpleRow_obj();
		Void __construct(::coopy::Table tab,int row_id);

	public:
		static hx::ObjectPtr< SimpleRow_obj > __new(::coopy::Table tab,int row_id);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SimpleRow_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		// hxcpp output massaged for SWIG //SWIGFIX
		inline ::hx::ObjectPtr< ::coopy::Datum_obj> asDatum() //SWIGFIX
			{ return ::hx::ObjectPtr< ::coopy::Datum_obj>(this); } //SWIGFIX
#ifndef SWIG //SWIGFIX
		inline operator ::coopy::Datum_obj *()
			{ return new ::coopy::Datum_delegate_< SimpleRow_obj >(this); }
#endif //SWIGFIX
		// hxcpp output massaged for SWIG //SWIGFIX
		inline ::hx::ObjectPtr< ::coopy::Bag_obj> asBag() //SWIGFIX
			{ return ::hx::ObjectPtr< ::coopy::Bag_obj>(this); } //SWIGFIX
#ifndef SWIG //SWIGFIX
		inline operator ::coopy::Bag_obj *()
			{ return new ::coopy::Bag_delegate_< SimpleRow_obj >(this); }
#endif //SWIGFIX
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SimpleRow"); }

		virtual ::coopy::View getItemView( );
		Dynamic getItemView_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::coopy::Table getTable( );
		Dynamic getTable_dyn();

		virtual Void setItem( int x,::coopy::Datum c);
		Dynamic setItem_dyn();

		virtual ::coopy::Datum getItem( int x);
		Dynamic getItem_dyn();

		virtual int get_size( );
		Dynamic get_size_dyn();

		::coopy::Bag bag;
		int row_id;
		::coopy::Table tab;
};

} // end namespace coopy

#endif /* INCLUDED_coopy_SimpleRow */ 
