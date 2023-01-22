if status is-interactive
    # Commands to run in interactive sessions can go here

#Programms that run at start

	setxkbmap es
	neofetch
	colorscript -r

#ALias
	alias install='sudo pacman -S'
	alias sync='sudo pacman -Syy'
	alias update='sudo pacman -Syu'
	alias off='poweroff'
	alias re='reboot'
	alias config='cd .config'
	alias trash='cd .local/share/Trash/'
	alias free='sudo rm -rf files'
	alias del='sudo pacman -R'
	alias cat='bat'
	alias ls='lsd'
	alias seeim='kitty +kitten icat'
# tricking the user bookmark
starship init fish | source

end

