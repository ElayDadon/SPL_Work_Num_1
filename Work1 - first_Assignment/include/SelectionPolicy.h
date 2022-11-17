#pragma once

class SelectionPolicy {public: virtual void select(); };

class MandatesSelectionPolicy: public SelectionPolicy{ public: virtual void select();};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ public: virtual void select();};