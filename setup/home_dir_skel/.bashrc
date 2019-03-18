#
# ~/.bashrc
#

# set environment variables
export TERM=xterm-256color

# Import aliases
if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# Source bash-completion
[[ $PS1 && -f /usr/share/bash-completion/bash_completion ]] && \
    . /usr/share/bash-completion/bash_completion

# Identify git branch
function parse_git_branch() {
    BRANCH=`git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1/'`
    if [ ! "${BRANCH}" == "" ]
    then
        echo " [${BRANCH}]"
    else
        echo ""
    fi
}

# These colors require xterm-256 colors
# TODO we should have a test for 256 colors, and fail-back to standard colors
GREEN="\[$(tput setaf 34)\]"
BLUE="\[$(tput setaf 27)\]"
PURPLE="\[$(tput setaf 57)\]"
RED="\[$(tput setaf 196)\]"
RESET="\[$(tput sgr0)\]"

# Set prompt color based on user
if [[ "$(whoami)" == "root" ]]; then
    PS1="${PURPLE}[${RED}\u${PURPLE}@\h \w]${RESET}\`parse_git_branch\`${PURPLE}\$${RESET} "
else
    PS1="${PURPLE}[\u@\h \w]${RESET}\`parse_git_branch\`${PURPLE}\$${RESET} "
fi

# PROMPT_COMMAND runs before displaying prompt
#   Save current working directory to volatile storage
PROMPT_COMMAND='pwd > "${XDG_RUNTIME_DIR}/.cwd"'

# New terminals cd into PWD, rather than at home dir
[[ -f "${XDG_RUNTIME_DIR}/.cwd" ]] && cd "$(< ${XDG_RUNTIME_DIR}/.cwd)"
