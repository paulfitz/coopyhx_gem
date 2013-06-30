#ifndef INCLUDED_coopy_SimpleTable
#define INCLUDED_coopy_SimpleTable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <coopy/Bag.h>
#include <coopy/Table.h>
HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS1(coopy,Bag)
HX_DECLARE_CLASS1(coopy,Datum)
HX_DECLARE_CLASS1(coopy,SimpleTable)
HX_DECLARE_CLASS1(coopy,Table)
HX_DECLARE_CLASS1(coopy,View)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
namespace coopy{


class HXCPP_CLASS_ATTRIBUTES  SimpleTable_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SimpleTable_obj OBJ_;
		SimpleTable_obj();
		Void __construct(int w,int h);

	public:
		static hx::ObjectPtr< SimpleTable_obj > __new(int w,int h);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SimpleTable_obj();

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
			{ return new ::coopy::Datum_delegate_< SimpleTable_obj >(this); }
#endif //SWIGFIX
		// hxcpp output massaged for SWIG //SWIGFIX
		inline ::hx::ObjectPtr< ::coopy::Bag_obj> asBag() //SWIGFIX
			{ return ::hx::ObjectPtr< ::coopy::Bag_obj>(this); } //SWIGFIX
#ifndef SWIG //SWIGFIX
		inline operator ::coopy::Bag_obj *()
			{ return new ::coopy::Bag_delegate_< SimpleTable_obj >(this); }
#endif //SWIGFIX
		// hxcpp output massaged for SWIG //SWIGFIX
		inline ::hx::ObjectPtr< ::coopy::Table_obj> asTable() //SWIGFIX
			{ return ::hx::ObjectPtr< ::coopy::Table_obj>(this); } //SWIGFIX
#ifndef SWIG //SWIGFIX
		inline operator ::coopy::Table_obj *()
			{ return new ::coopy::Table_delegate_< SimpleTable_obj >(this); }
#endif //SWIGFIX
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("SimpleTable"); }

		virtual bool trimBlank( );
		Dynamic trimBlank_dyn();

		virtual bool insertOrDeleteColumns( Array< int > fate,int wfate);
		Dynamic insertOrDeleteColumns_dyn();

		virtual bool insertOrDeleteRows( Array< int > fate,int hfate);
		Dynamic insertOrDeleteRows_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual bool resize( int w,int h);
		Dynamic resize_dyn();

		virtual bool isResizable( );
		Dynamic isResizable_dyn();

		virtual ::coopy::View getItemView( );
		Dynamic getItemView_dyn();

		virtual ::coopy::View getCellView( );
		Dynamic getCellView_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::coopy::Datum getItem( int y);
		Dynamic getItem_dyn();

		virtual Void setCell( int x,int y,::coopy::Datum c);
		Dynamic setCell_dyn();

		virtual ::coopy::Datum getCell( int x,int y);
		Dynamic getCell_dyn();

		virtual int get_size( );
		Dynamic get_size_dyn();

		virtual int get_height( );
		Dynamic get_height_dyn();

		virtual int get_width( );
		Dynamic get_width_dyn();

		virtual ::coopy::Table getTable( );
		Dynamic getTable_dyn();

		::coopy::Bag bag;
		int h;
		int w;
		::haxe::ds::IntMap data;
		static ::String tableToString( ::coopy::Table tab);
		static Dynamic tableToString_dyn();

};

} // end namespace coopy

#endif /* INCLUDED_coopy_SimpleTable */ 
