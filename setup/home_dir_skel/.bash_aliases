#
# ~/.bash_aliases
#

alias grep='grep --color=auto'
alias ls='ls --color=auto'
alias pacman='pacman --color=auto'
function tunnelbear { sudo systemctl "$1" openvpn-client@TunnelBearUnitedStates.service; }
