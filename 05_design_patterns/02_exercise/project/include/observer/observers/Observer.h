//
// Created by Michał Podstawski on 13/12/2020.
//

#pragma once

namespace observer::observers{
        class Observer{
        public:
            virtual ~Observer() = default;
            virtual void notify(float){

            };
        };
    }

