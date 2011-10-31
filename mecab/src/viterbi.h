//  MeCab -- Yet Another Part-of-Speech and Morphological Analyzer
//
//  $Id: viterbi.h 173 2009-04-18 08:10:57Z taku-ku $;
//
//  Copyright(C) 2001-2006 Taku Kudo <taku@chasen.org>
//  Copyright(C) 2004-2006 Nippon Telegraph and Telephone Corporation
#ifndef MECAB_VITERBI_H_
#define MECAB_VITERBI_H_

#include <vector>
#include "mecab.h"

namespace MeCab {

class Lattice;
class Param;
class Connector;
class Model;
template <typename N, typename P> class Tokenizer;

class Viterbi {
 public:
  bool open(const Param &param,
            const Tokenizer<Node, Path> *tokenizer,
            const Connector *connector);

  bool analyze(Lattice *lattice) const;

  Viterbi();
  virtual ~Viterbi();

 private:
  bool viterbiWithAllPath(Lattice *lattice) const;
  bool viterbi(Lattice *lattice) const;
  bool initPartial(Lattice *lattice) const;
  bool initNBest(Lattice *lattice) const;
  bool forwardbackward(Lattice *lattice) const;
  bool buildBestLattice(Lattice *lattice) const;
  bool buildAllLattice(Lattice *lattice) const;
  Node *filterNode(Node *constrained_node, Node *node) const;

  const Tokenizer<Node, Path> *tokenizer_;
  const Connector             *connector_;
  int    cost_factor_;
};
}
#endif  // MECAB_VITERBI_H_
