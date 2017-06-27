//
// Created by Dean DU TOIT on 2017/06/27.
//
#pragma once

#include <Operand.hpp>
#include <iostream>

class OperandFactory;

typedef IOperand const * fptr;
typedef IOperand const *  (OperandFactory::*createType)( std::string const & value ) const;  // Please do this!

class OperandFactory
{
private:
	createType 					create[5];
	IOperand const 				*createInt8( std::string const & value ) const;
	IOperand const				*createInt16( std::string const & value ) const;
	IOperand const 				*createInt32( std::string const & value ) const;
	IOperand const 				*createFloat( std::string const & value ) const;
	IOperand const 				*createDouble( std::string const & value ) const;

public:
	OperandFactory();
	OperandFactory(const OperandFactory &src);
	~OperandFactory();

	IOperand const 				*createOperand( eOperandType type, std::string const & value ) const;
	OperandFactory				&operator=(const OperandFactory &src);
};
