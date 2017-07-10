//
// Created by Dean DU TOIT on 2017/06/27.
//

#ifndef AVM_INT8_HPP
#define AVM_INT8_HPP

#include <cstdint>
#include <iostream>
#include <float.h>
#include <cmath>
#include <Parser.hpp>
#include "IOperand.hpp"

enum eOperation
{
	Sum,
	Difference,
 	Product,
 	Quotient,
  	Modulo,
};

template <typename T>
class Operand : public IOperand
{
private:
	const T 				val;
	const eOperandType		type;
	std::string				str;

	Operand( void )	{}

public:
	Operand(eOperandType _type, T _val) : val(_val), type(_type)
	{
		str = std::to_string(val);
		while( (str.find(".")!= std::string::npos
			   && str.substr( str.length() - 1, 1) == "0")
			   || str.substr( str.length() - 1, 1) == "." )
		{
			str.pop_back();
		}
	}

	Operand(Operand &src) : type(src.type), val(src.val), str(src.str)
	{
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

	inline eOperandType getRetType(IOperand const & rhs ) const
	{
		if (type == rhs.getType())
			return (type);
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

	template <typename T1>
	T1				doOp(T1 v1, eOperation e, eOperandType restype) const
	{
		T1			ret;

		switch (e)
		{
			case Sum :
				if (restype == TFLOAT || restype == TDOUBLE)
				{
					long double lim = val + v1;
					checkLim(lim, restype);
				}
				else
				{
					int64_t lim = val + v1;
					checkLim(lim, restype);
				}
				ret = val + v1;
				break;
			case Difference :
				if (restype == TFLOAT || restype == TDOUBLE)
				{
					long double lim = val - v1;
					checkLim(lim, restype);
				}
				else
				{
					int64_t lim = val - v1;
					checkLim(lim, restype);
				}
				ret = val - v1;
				break;
			case Product :
				if (restype == TFLOAT || restype == TDOUBLE)
				{
					long double lim = val * v1;
					checkLim(lim, restype);
				}
				else
				{
					int64_t lim = val * v1;
					checkLim(lim, restype);
				}
				ret = val * v1;
				break;
			case Quotient :
				if (v1 == 0)
					throw (Parser::DivisionByZeroException());
				if (restype == TFLOAT || restype == TDOUBLE)
				{
					long double lim = val / v1;
					checkLim(lim, restype);
				}
				else
				{
					int64_t lim = val / v1;
					checkLim(lim, restype);
				}
				ret = val / v1;
				break;
			case Modulo :
				if (v1 == 0)
					throw (Parser::DivisionByZeroException());
				if (restype == TFLOAT || restype == TDOUBLE)
				{
					long double lim = fmod(val, v1);
					checkLim(lim, restype);
				}
				else
				{
					int64_t lim = fmod(val, v1);
					checkLim(lim, restype);
				}
				ret = fmod(val, v1);
				break;
		}
		return (ret);
	}

	template <typename T1>
	void				checkLim(T1 v, eOperandType type) const
	{
		switch (type)
		{
			case TINT8 :
				if (v > INT8_MAX)
					throw (Parser::ValueOverflowException());
				if (v < INT8_MIN)
					throw (Parser::ValueUnderflowException());
				break;
			case TINT16 :
				if (v > INT16_MAX)
					throw (Parser::ValueOverflowException());
				if (v < INT16_MIN)
					throw (Parser::ValueUnderflowException());
				break;
			case TINT32 :
				if (v > INT32_MAX)
					throw (Parser::ValueOverflowException());
				if (v < INT32_MIN)
					throw (Parser::ValueUnderflowException());
				break;
			case TFLOAT :
				if (v > FLT_MAX)
					throw (Parser::ValueOverflowException());
				if (v < -FLT_MAX)
					throw (Parser::ValueUnderflowException());
				break;
			case TDOUBLE :
				if (v > DBL_MAX)
					throw (Parser::ValueOverflowException());
				if (v < -DBL_MAX)
					throw (Parser::ValueUnderflowException());
				break;
		}
	}

	IOperand const		*calc(IOperand const & rhs, eOperation operation) const
	{
		eOperandType retType = getRetType(rhs);
		std::string	op_s = rhs.toString();

		switch(retType)
		{
			case TINT8:
				return (new Operand<int8_t>(retType, doOp(std::stoi(op_s), operation, retType)));
			case TINT16:
				return (new Operand<int16_t>(retType, doOp(std::stoi(op_s), operation, retType)));
			case TINT32:
				return (new Operand<int32_t>(retType, doOp(std::stoi(op_s), operation, retType)));
			case TFLOAT:
				return (new Operand<float>(retType, doOp(std::stof(op_s), operation, retType)));
			case TDOUBLE:
				return (new Operand<double>(retType, doOp(std::stod(op_s), operation, retType)));
		}
	}

	IOperand const		*operator+( IOperand const & rhs ) const
	{
		return (calc(rhs, Sum));
	}

	IOperand const		*operator-( IOperand const & rhs ) const
	{
		return (calc(rhs, Difference));
	}

	IOperand const		*operator*( IOperand const & rhs ) const
	{
		return (calc(rhs, Product));
	}

	IOperand const		*operator/( IOperand const & rhs ) const
	{
		return (calc(rhs, Quotient));
	}

	IOperand const		*operator%( IOperand const & rhs ) const
	{
		return (calc(rhs, Modulo));
	}

	std::string const 	&toString( void ) const
	{
		return (str);
	}
};

#endif //AVM_INT8_HPP
