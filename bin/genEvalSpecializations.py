#! /usr/bin/python

import os
import sys
import jinja2

fileNames = []

specializationTemplate = \
"""// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*
  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the list of
  copyright holders.
*/
/*!
 * \\file
 *
 * \\brief This file specializes the dense-AD Evaluation class for {{ numDerivs }} derivatives.
 *
 * \\attention THIS FILE GETS AUTOMATICALLY GENERATED BY THE "{{ scriptName }}"
 *            SCRIPT. DO NOT EDIT IT MANUALLY!
 */
#ifndef OPM_DENSEAD_EVALUATION{{numDerivs}}_HPP
#define OPM_DENSEAD_EVALUATION{{numDerivs}}_HPP

namespace Opm {
namespace DenseAd {

template <class ValueT>
struct EvaluationOps<ValueT, {{numDerivs}}>
{
private:
    typedef Evaluation<ValueT, {{numDerivs}} > Eval;

public:
    typedef std::array<ValueT, {{numDerivs + 1}} > DataVector;

    static inline void assign(Eval& a, const Eval& b)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] = b.data_[{{i}}];{% endfor %}
    }

    static inline void assignNegative(Eval& a, const Eval& b)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] = - b.data_[{{i}}];{% endfor %}
    }

    static inline void clearDerivatives(Eval& a)
    {
{% for i in range(1, numDerivs+1) %}
        a.data_[{{i}}] = 0.0;{% endfor %}
    }

    static inline Eval& addEq(Eval& a, const Eval& b)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] += b.data_[{{i}}];{% endfor %}

        return a;
    }

    static inline Eval& subEq(Eval& a, const Eval& b)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] -= b.data_[{{i}}];{% endfor %}

        return a;
    }

    static inline Eval& mulEq(Eval& a, const Eval& b)
    {
        // while the values are multiplied, the derivatives follow the product rule,
        // i.e., (u*v)' = (v'u + u'v).
        const ValueT u = a.value();
        const ValueT v = b.value();

        // value
        a.data_[0] *= v ;

        //  derivatives{% for i in range(1, numDerivs+1) %}
        a.data_[{{i}}] = a.data_[{{i}}]*v + b.data_[{{i}}] * u;{% endfor %}

        return a;
    }

    template <class RhsType>
    static inline Eval& scalarMulEq(Eval& a, const RhsType& other)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] *= other;{% endfor %}

        return a;
    }

    static inline Eval& divEq(Eval& a, const Eval& b)
    {
        // values are divided, derivatives follow the rule for division, i.e., (u/v)' = (v'u - u'v)/v^2.
        const ValueT v_vv = 1.0 / b.value();
        const ValueT u_vv = a.value() * v_vv * v_vv;

        // value
        a.data_[0] *= v_vv;

        //  derivatives{% for i in range(1, numDerivs+1) %}
        a.data_[{{i}}] = a.data_[{{i}}]*v_vv - b.data_[{{i}}]*u_vv;{% endfor %}

        return a;
    }

    template <class RhsType>
    static inline Eval& scalarDivEq(Eval& a, const RhsType& other)
    {
{% for i in range(0, numDerivs+1) %}
        a.data_[{{i}}] /= other;{% endfor %}

        return a;
    }

    template <class RhsValueType>
    static inline Eval divide(const RhsValueType& a, const Eval& b)
    {
        Eval result;
        result.setValue( a/b.value() );
        const ValueT df_dg = - result.value()/b.value();
{% for i in range(1, numDerivs+1) %}
        result.data_[{{i}}] = df_dg*b.data_[{{i}}];{% endfor %}

        return result;
    }
};

} } // namespace DenseAd, Opm

#endif // OPM_DENSEAD_EVALUATION{{numDerivs}}_HPP
"""

includeSpecializationsTemplate = \
"""// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*
  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the list of
  copyright holders.
*/
/*!
 * \\file
 *
 * \\brief This file includes all specializations for the dense-AD Evaluation class.
 *
 * \\attention THIS FILE GETS AUTOMATICALLY GENERATED BY THE "{{ scriptName }}"
 *            SCRIPT. DO NOT EDIT IT MANUALLY!
 */
#ifndef OPM_DENSEAD_EVALUATION_SPECIALIZATIONS_HPP
#define OPM_DENSEAD_EVALUATION_SPECIALIZATIONS_HPP

{% for fileName in fileNames %}#include <{{ fileName }}>
{% endfor %}

#endif // OPM_DENSEAD_EVALUATION_SPECIALIZATIONS_HPP
"""

for numDerivs in range(1, 12 + 1):
    print "Generating specialization for %d derivatives"%numDerivs

    fileName = "opm/material/densead/Evaluation%d.hpp"%numDerivs
    fileNames.append(fileName)

    template = jinja2.Template(specializationTemplate)
    fileContents = template.render(numDerivs=numDerivs, scriptName=os.path.basename(sys.argv[0]))

    f = open(fileName, "w")
    f.write(fileContents)
    f.close()

template = jinja2.Template(includeSpecializationsTemplate)
fileContents = template.render(fileNames=fileNames, scriptName=os.path.basename(sys.argv[0]))

f = open("opm/material/densead/EvaluationSpecializations.hpp", "w")
f.write(fileContents)
f.close()
