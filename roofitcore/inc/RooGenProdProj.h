/*****************************************************************************
 * Project: RooFit                                                           *
 * Package: RooFitCore                                                       *
 *    File: $Id: RooGenProdProj.rdl,v 1.5 2005/02/14 20:44:25 wverkerke Exp $
 * Authors:                                                                  *
 *   WV, Wouter Verkerke, UC Santa Barbara, verkerke@slac.stanford.edu       *
 *   DK, David Kirkby,    UC Irvine,         dkirkby@uci.edu                 *
 *                                                                           *
 * Copyright (c) 2000-2005, Regents of the University of California          *
 *                          and Stanford University. All rights reserved.    *
 *                                                                           *
 * Redistribution and use in source and binary forms,                        *
 * with or without modification, are permitted according to the terms        *
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)             *
 *****************************************************************************/
#ifndef ROO_GEN_PROD_PROJ
#define ROO_GEN_PROD_PROJ

#include "RooFitCore/RooAbsReal.hh"
#include "RooFitCore/RooSetProxy.hh"
#include "RooFitCore/RooListProxy.hh"

class RooRealVar;
class RooArgList ;

class RooGenProdProj : public RooAbsReal {
public:

  RooGenProdProj() ;
  RooGenProdProj(const char *name, const char *title, const RooArgSet& _prodSet, const RooArgSet& _intSet, const RooArgSet& _normSet, const char* isetRangeName) ;

  RooGenProdProj(const RooGenProdProj& other, const char* name = 0);
  virtual TObject* clone(const char* newname) const { return new RooGenProdProj(*this, newname); }
  virtual ~RooGenProdProj() ;

protected:

  RooAbsReal* makeIntegral(const char* name, const RooArgSet& compSet, const RooArgSet& intSet, RooArgSet& saveSet, const char* isetRangeName) ;

  virtual void operModeHook() ;

  Double_t evaluate() const;
  RooArgSet* _compSetOwnedN ; // Owner of numerator components 
  RooArgSet* _compSetOwnedD ; // Owner of denominator components
  RooSetProxy _compSetN ; // Set proxy for numerator components 
  RooSetProxy _compSetD ; // Set proxy for denominator components 
  RooListProxy _intList ; // Master integrals representing numerator and denominator
  Bool_t _haveD ;         // Do we have a denominator term?

  ClassDef(RooGenProdProj,1) // General form of projected integral of product of PDFs 
};

#endif
