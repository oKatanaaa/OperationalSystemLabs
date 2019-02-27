cmake_minimum_required(VERSION 3.13)
project(Lab1_Bessel_Function)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab1_Bessel_Function
        headers/Functions/Const.h
        headers/Functions/Cos.h
        headers/Functions/Exp.h
        headers/Functions/Function.h
        headers/MetaFunctions/FunctionComposition.h
        headers/Factories/FunctionFactory.h
        headers/MetaFunctions/FunctionMultiplication.h
        headers/MetaFunctions/FunctionParameterizedIntegral.h
        headers/MetaFunctions/FunctionPower.h
        headers/MetaFunctions/FunctionSum.h
        headers/Functions/Identity.h
        headers/Utils/Integrator.h
        headers/Functions/Sin.h
        headers/Functions/Sinh.h
        source/Source.cpp
        headers/Functions/SphercialBesselFun.h
        headers/TwoFunction/TwoFunction.h
        headers/Factories/TwoFunctionFactory.h
        headers/MetaTwoFunctions/TwoFunctionMultiplication.h
        headers/MetaTwoFunctions/TwoFunctionSum.h
        headers/MetaTwoFunctions/TwoFunctionTwoSum.h
        headers/MetaTwoFunctions/TwoFunctionWrapper.h)
