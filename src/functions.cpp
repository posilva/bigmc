// ==========================================================================
// Copyright (C) 2013 Força Aérea Portuguesa - Academia                     =
// Centro de Investigação da Academiafa da Força Aérea                      =
// Granja do Marques, Academia, Pero-Pinheiro                               =
// ==========================================================================
// Project: bigmc
// Date:    Apr 17, 2013                                
// Author:  posilva                                
// -------------------------------------------------------------------------=
// Change Log:                                                         
// -------------------------------------------------------------------------=
// Date       / Author              /Description                          
// ==========================================================================
// Description: functions.cpp
// 
// ==========================================================================
#include <iostream>
#include <string>
#include <bigmc.h>

functions::functions()
{
}

functions::~functions()
{
}

void
register_predicates()
{
  predicate::register_predicate("empty", new pred_empty());
  predicate::register_predicate("size", new pred_size());
  predicate::register_predicate("matches", new pred_matches());
  predicate::register_predicate("terminal", new pred_terminal());
  predicate::register_predicate("equal", new pred_equal());
}
std::string
functions::get_next_step(std::string model)
{
  global_cfg.debug = false;
  global_cfg.verbose_level = 0;
  global_cfg.max_steps = 2;
  global_cfg.report_interval = 0;
  global_cfg.graph_out = NULL;
  global_cfg.check_local = false;
  global_cfg.threads = 2;
  global_cfg.print_mode = false;
  global_cfg.analyse_only = false;
  global_cfg.calculation = false;
  global_cfg.function_mode = true;

  register_predicates();
  std::string result;
  parser::init(NULL);
  try
  {
    results_map results;
    parser::parse_function(model, results);
    if (results.size() > 1)
    {
      result= results[1];
    }
  }
  catch (const std::bad_alloc&)
  {
    rerror("top-level")
        << "Oh dear.  We hit a bad_alloc exception.  This usually means you ran out of memory."
        << endl;
  }
  parser::cleanup();
  return result;
}
