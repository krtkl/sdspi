###############################################################################
#
#   Constraints file for snickerdoodle
#
#   Copyright (c) 2018 krtkl inc.
#
###############################################################################
#
#------------------------------------------------------------------------------
#   JA1.4       G14 |   JA2.4       J15 |   JB1.4       T19 |   JB2.4       R19
#   JA1.5       E18 |   JA2.5       L14 |   JB1.5       T11 |   JB2.5       N17
#   JA1.6       D20 |   JA2.6       J16 |   JB1.6       U12 |   JB2.6       P16
#   JA1.7       E19 |   JA2.7       L15 |   JB1.7       T10 |   JB2.7       P18
#   JA1.8       D19 |   JA2.8       K16 |   JB1.8       T12 |   JB2.8       P15
#   JA1.11      F16 |   JA2.11      M14 |   JB1.11      P14 |   JB2.11      T17
#   JA1.12      B20 |   JA2.12      G15 |   JB1.12      W13 |   JB2.12      R17
#   JA1.13      F17 |   JA2.13      M15 |   JB1.13      R14 |   JB2.13      R18
#   JA1.14      C20 |   JA2.14      H15 |   JB1.14      V12 |   JB2.14      R16
#   JA1.17      E17 |   JA2.17      N15 |   JB1.17      U13 |   JB2.17      V17
#   JA1.18      A20 |   JA2.18      J14 |   JB1.18      T15 |   JB2.18      W19
#   JA1.19      D18 |   JA2.19      N16 |   JB1.19      V13 |   JB2.19      V18
#   JA1.20      B19 |   JA2.20      K14 |   JB1.20      T14 |   JB2.20      W18
#   JA1.23      F19 |   JA2.23      L19 |   JB1.23      T16 |   JB2.23      T20
#   JA1.24      G20 |   JA2.24      J19 |   JB1.24      Y17 |   JB2.24      W16
#   JA1.25      F20 |   JA2.25      L20 |   JB1.25      U17 |   JB2.25      U20
#   JA1.26      G19 |   JA2.26      K19 |   JB1.26      Y16 |   JB2.26      V16
#   JA1.29      J20 |   JA2.29      M17 |   JB1.29      W14 |   JB2.29      V20
#   JA1.30      G18 |   JA2.30      M20 |   JB1.30      W15 |   JB2.30      Y19
#   JA1.31      H20 |   JA2.31      M18 |   JB1.31      Y14 |   JB2.31      W20
#   JA1.32      G17 |   JA2.32      M19 |   JB1.32      V15 |   JB2.32      Y18
#   JA1.35      J18 |   JA2.35      L16 |   JB1.35      U14 |   JB2.35      N20
#   JA1.36      H17 |   JA2.36      K18 |   JB1.36      U19 |   JB2.36      P19
#   JA1.37      H18 |   JA2.37      L17 |   JB1.37      U15 |   JB2.37      P20
#   JA1.38      H16 |   JA2.38      K17 |   JB1.38      U18 |   JB2.38      N18
#------------------------------------------------------------------------------


set_property PACKAGE_PIN E18 [get_ports SPI0_MISO_I];           # JA1.5
set_property PACKAGE_PIN D20 [get_ports SPI0_MOSI_O];           # JA1.6
set_property PACKAGE_PIN E19 [get_ports SPI0_SCLK_O];           # JA1.7
set_property PACKAGE_PIN D19 [get_ports SPI0_SS_O];             # JA1.8

set_property IOSTANDARD LVCMOS33 [list [get_ports SPI0_*]]
