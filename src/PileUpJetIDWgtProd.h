#ifndef PileUpJetIDWgtProd_h
#define PileUpJetIDWgtProd_h

/* -*- C++ -*-
 *
 * Class: PileUpJetIDWgtProd
 * Based on recipe by Laurent Thomas @ CMS
 * Twiki: https://twiki.cern.ch/twiki/bin/viewauth/CMS/PileupJetID
 * Source: 
 * Goal: calculate event weights for Pile Up Jet ID. 
 * Adapted by: Dale Julson.
 * Date: Dec 1, 2020
*/
#include <iostream>
#include <memory>
#include <TFile.h>   // TFile
#include <TString.h> // Form
#include <string>    // std::string
#include <vector>    // std::vector
#include <map>       // std::map
#include <TH2.h>
#include "Particle.h"

//enum variations {central = 0, up, down};

class PileUpJetIDWgtProd{
	public:
		PileUpJetIDWgtProd() { };
		PileUpJetIDWgtProd(const std::string& datapath, const std::string& year, const bool useEMpt=false);
		~L1ECALPrefiringWgtProd() { };

		void produceWeights(Photon& photons, Jet& jets);
		void resetWeights();
		float getPileUpJetIDWeight(const std::string& syst_name="");

	private:

		float getPileUpJetIDRate(double eta, double pt, TH2F* h_prefmap, variations var);
		float nonPileUpJetIDProbability[3] = {1.0, 1.0, 1.0}; // 0: central, 1: up, 2: down

		TString photonmapname;
		TString jetmapname;
		TString filename_photonmap;
		TString filename_jetmap;
		TH2F* h_prefmap_photon;
		TH2F* h_prefmap_jet;
		bool useEMpt_;
		std::string dataera_;
		double prefiringRateSystUnc_;

};

#endif