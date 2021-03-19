= ARRAY_CONSTRAIN(ARRAYFORMULA(CONCATENATE(
                      IF(ISERROR(SEARCH("Off", Lays !B3)), "", CONCATENATE(Lays !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Raissa !B3)), "", CONCATENATE(Raissa !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Default !B3)), "", CONCATENATE(Default !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Felipe !B3)), "", CONCATENATE(Felipe !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Emerson !B3)), "", CONCATENATE(Emerson !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Guilherme !B3)), "", CONCATENATE(Guilherme !$A$1, " / ")),
                      IF(ISERROR(SEARCH("Off", Lucas !B3)), "", CONCATENATE(Lucas !$A$1, " / ")))),
                  1, 1)