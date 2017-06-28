//
// Created by Dean DU TOIT on 2017/06/27.
//

#include "OperandFactory.hpp"

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
	return (new Operand<int8_t >(TINT8, std::stoi(value)));
}

IOperand const *OperandFactory::createInt16(std::string const &value) const
{
	return (new Operand<int16_t >(TINT16, std::stoi(value)));
}

IOperand const *OperandFactory::createInt32(std::string const &value) const
{
	return (new Operand<int32_t >(TINT32, std::stoi(value)));
}

IOperand const *OperandFactory::createFloat(std::string const &value) const
{
	return (new Operand<float>(TFLOAT, std::stof(value)));
}

IOperand const *OperandFactory::createDouble(std::string const &value) const
{
	return (new Operand<double>(TDOUBLE, std::stod(value)));
}

OperandFactory::OperandFactory()
{
	create[TINT8] = &OperandFactory::createInt8;
	create[TINT16] = &OperandFactory::createInt16;
	create[TINT32] = &OperandFactory::createInt32;
	create[TFLOAT] = &OperandFactory::createFloat;
	create[TDOUBLE] = &OperandFactory::createDouble;
}

OperandFactory::OperandFactory(const OperandFactory &src)
{
	*this = src;
}

OperandFactory::~OperandFactory()
{
}

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
	if (type >= TINT8 && type <= TDOUBLE)
	{
		return ((this->*(create[type]))(value));
	}
	return nullptr;
}

OperandFactory &OperandFactory::operator=(const OperandFactory &src)
{
	memcpy(&create, &src.create, sizeof(createType) * 5);
	return *this;
}
