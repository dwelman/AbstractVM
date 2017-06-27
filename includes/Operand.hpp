//
// Created by Dean DU TOIT on 2017/06/27.
//

#ifndef AVM_INT8_HPP
#define AVM_INT8_HPP

#include <cstdint>
#include <iostream>
#include "IOperand.hpp"

template <typename T1, typename T2>
IOperand const		*doModulo( IOperand const & o1, IOperand const & o2 );

template <typename T>
class Operand : public IOperand
{
private:
//	static OperandFactory	faco
	T 						val;
	const eOperandType		type;
	std::string				str;

	Operand( void )	{}
public:

	Operand(eOperandType _type, T _val) : type(_type), val(_val)
	{
		str = std::to_string(val);
	}

	void	setVal(T val)
	{
		this->val = val;
	}

	int 				getPrecision( void ) const
	{
		return (sizeof(T));
	}

	eOperandType 		getType( void ) const
	{
		return (type);
	}

	inline eOperandType getRetType(IOperand const & rhs )
	{
		eOperandType retType;

		if (getPrecision() == rhs.getPrecision())
		{
			if (type == TDOUBLE || rhs.getType() == TDOUBLE)
				return TDOUBLE;
			else if (type == TFLOAT || rhs.getType() == TFLOAT)
				return TFLOAT;
			else
				return TINT32;
		}
		else
			return (( getPrecision() > rhs.getPrecision() ) ? type : rhs.getType());
	}
	IOperand const		*operator+( IOperand const & rhs ) const
	{
		std::string	op_s = rhs.toString();
		if (getType() == rhs.getType())
		{
			T op ;
			switch(type)
			{
				case TINT8:
				case TINT16:
				case TINT32:
					return (new Operand<T>(type, val + std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<T>(type, val + std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<T>(type, val + std::stod(op_s)));
			}
			return (new Operand<T>(type, val + op));
		}
		else
		{
			eOperandType retType = getType();
			switch(retType)
			{
				case TINT8:
					return (new Operand<int8_t>(retType, val + std::stoi(op_s)));
				case TINT16:
					return (new Operand<int16_t>(retType, val + std::stoi(op_s)));
				case TINT32:
					return (new Operand<int32_t>(retType, val + std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<float>(retType, val + std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<double>(retType, val + std::stod(op_s)));
			}

		}
	}

	IOperand const		*operator-( IOperand const & rhs ) const
	{
		std::string	op_s = rhs.toString();
		if (getType() == rhs.getType())
		{
			T op ;
			switch(type)
			{
				case TINT8:
				case TINT16:
				case TINT32:
					return (new Operand<T>(type, val - std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<T>(type, val - std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<T>(type, val - std::stod(op_s)));
			}
			return (new Operand<T>(type, val - op));
		}
		else
		{
			eOperandType retType = getType();
			switch(retType)
			{
				case TINT8:
					return (new Operand<int8_t>(retType, val - std::stoi(op_s)));
				case TINT16:
					return (new Operand<int16_t>(retType, val - std::stoi(op_s)));
				case TINT32:
					return (new Operand<int32_t>(retType, val - std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<float>(retType, val - std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<double>(retType, val - std::stod(op_s)));
			}

		}
	}

	IOperand const		*operator*( IOperand const & rhs ) const
	{
		std::string	op_s = rhs.toString();
		if (getType() == rhs.getType())
		{
			T op ;
			switch(type)
			{
				case TINT8:
				case TINT16:
				case TINT32:
					return (new Operand<T>(type, val * std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<T>(type, val * std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<T>(type, val * std::stod(op_s)));
			}
			return (new Operand<T>(type, val * op));
		}
		else
		{
			eOperandType retType = getType();
			switch(retType)
			{
				case TINT8:
					return (new Operand<int8_t>(retType, val * std::stoi(op_s)));
				case TINT16:
					return (new Operand<int16_t>(retType, val * std::stoi(op_s)));
				case TINT32:
					return (new Operand<int32_t>(retType, val * std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<float>(retType, val * std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<double>(retType, val * std::stod(op_s)));
			}

		}
	}

	IOperand const		*operator/( IOperand const & rhs ) const
	{
		std::string	op_s = rhs.toString();
		if (getType() == rhs.getType())
		{
			T op ;
			switch(type)
			{
				case TINT8:
				case TINT16:
				case TINT32:
					return (new Operand<T>(type, val / std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<T>(type, val / std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<T>(type, val / std::stod(op_s)));
			}
			return (new Operand<T>(type, val / op));
		}
		else
		{
			eOperandType retType = getType();
			switch(retType)
			{
				case TINT8:
					return (new Operand<int8_t>(retType, val / std::stoi(op_s)));
				case TINT16:
					return (new Operand<int16_t>(retType, val / std::stoi(op_s)));
				case TINT32:
					return (new Operand<int32_t>(retType, val / std::stoi(op_s)));
				case TFLOAT:
					return (new Operand<float>(retType, val / std::stof(op_s)));
				case TDOUBLE:
					return (new Operand<double>(retType, val / std::stod(op_s)));
			}

		}
	}

	/*IOperand const		*operator%( IOperand const & rhs ) const
	{
		std::string	op_s = rhs.toString();
		if (getType() == rhs.getType())
		{
			T op ;
			switch(type)
			{
				case TINT8:
				case TINT16:
				case TINT32:
					return (new Operand<T>(type, val % std::stoi(op_s)));
				case TFLOAT:
				case TDOUBLE:
					return (nullptr);
			}
			return (new Operand<T>(type, val % op));
		}
		else
		{
			eOperandType retType = getType();
			switch(retType)
			{
				case TINT8:
					return (new Operand<int8_t>(retType, val % std::stoi(op_s)));
				case TINT16:
					return (new Operand<int16_t>(retType, val % std::stoi(op_s)));
				case TINT32:
					return (new Operand<int32_t>(retType, val % std::stoi(op_s)));
				case TFLOAT:
				case TDOUBLE:
					return (nullptr);
			}

		}
	}
*/

	IOperand const		*operator%( IOperand const & rhs ) const
	{
		switch (rhs.getType())
		{
			case TINT8 :
				return (doModulo<T, int8_t >(*this, rhs));
			case TINT16 :
				return (doModulo<T, int16_t >(*this, rhs));
			case TINT32 :
				return (doModulo<T, int32_t >(*this, rhs));
			default:
				return nullptr;
		}
	}

	std::string const 	&toString( void ) const
	{
		return (str);
	}
};

template <typename T1, typename T2>
IOperand const		*doModulo( IOperand const & o1, IOperand const & o2 )
{
	std::string	op_s1 = o1.toString();
	std::string	op_s2 = o2.toString();

	if (o1.getType() == o2.getType())
	{
		return (new Operand<T1>(o1.getType() , std::stoi(op_s1) % std::stoi(op_s2)));
	}
	else
	{
		eOperandType retType;

		if (o1.getPrecision() == o2.getPrecision())
		{
			if (o1.getType() == TDOUBLE || o2.getType() == TDOUBLE)
				retType = TDOUBLE;
			else if (o1.getType() == TFLOAT || o2.getType() == TFLOAT)
				retType = TFLOAT;
			else
				retType = TINT32;
		}
		else
			retType = ( o1.getPrecision() > o2.getPrecision() ) ? o1.getType() : o2.getType();

		switch(retType)
		{
			case TINT8:
				return (new Operand<int8_t>(retType, std::stoi(op_s1) % std::stoi(op_s2)));
			case TINT16:
				return (new Operand<int16_t>(retType, std::stoi(op_s1) % std::stoi(op_s2)));
			case TINT32:
				return (new Operand<int32_t>(retType, std::stoi(op_s1) % std::stoi(op_s2)));
			default :
				return (nullptr);
		}
	}
}

/*
std::ostream& operator<<(std::ostream& os, const IOperand& dt)
{
	os << dt.toString();
}
*/

#endif //AVM_INT8_HPP
