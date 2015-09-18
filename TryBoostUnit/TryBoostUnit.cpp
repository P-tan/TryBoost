#include "stdafx.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/make_scaled_unit.hpp>

#define DEFINE_QUANTITY(unit, symbol) \
	typedef boost::units::quantity<unit, int8_t> SI8_##symbol;\
	typedef boost::units::quantity<unit, int16_t> SI16_##symbol;\
	typedef boost::units::quantity<unit, int32_t> SI32_##symbol;\
	typedef boost::units::quantity<unit, int64_t> SI64_##symbol;\
	typedef boost::units::quantity<unit, uint8_t>  UI8_##symbol;\
	typedef boost::units::quantity<unit, uint16_t> UI16_##symbol;\
	typedef boost::units::quantity<unit, uint32_t> UI32_##symbol;\
	typedef boost::units::quantity<unit, uint64_t> UI64_##symbol;\
	typedef boost::units::quantity<unit, float> F32_##symbol;\
	typedef boost::units::quantity<unit, double> F64_##symbol;\

#define DEFINE_UNIT(unit, symbol) \
	typedef unit Unit_##symbol;\
	BOOST_STATIC_CONSTANT(Unit_##symbol, unit_##symbol);\
	DEFINE_QUANTITY(Unit_##symbol, symbol);

#define DEFINE_SCALED_UNIT(unit, scale_num, symbol) \
	typedef boost::units::make_scaled_unit<unit, boost::units::scale<10, boost::units::static_rational<scale_num> > > Unit_##symbol;\
	BOOST_STATIC_CONSTANT(Unit_##symbol, unit_##symbol);\
	DEFINE_QUANTITY(Unit_##symbol, symbol);

#define DEFINE_SCALED_UNITS(unit, symbol) \
	DEFINE_UNIT(unit,symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -1, 0_1##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -2, 0_01##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -3, m##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -4, 0_1m##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -5, 0_01m##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -6, u##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -7, 0_1u##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -8, 0_01u##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -9, n##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -10, 0_1n##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -11, 0_01n##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, -12, p##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 1, 10##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 2, 100##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 3, k##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 4, 10k##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 5, 100k##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 6, M##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 7, 10M##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 8, 100M##symbol);\
	DEFINE_SCALED_UNIT(Unit_##symbol, 9, G##symbol);\

int main()
{
	DEFINE_SCALED_UNITS(boost::units::si::electric_potential, V);


	SI8_V volt;
	UI64_V volt2;
	SI8_kV kv;
	F64_kV kv2;
	F32_nV nv;
    return 0;
}

