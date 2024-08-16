
" Configuration inspired by https://github.com/NeuralNine/config-files/blob/master/init.vim

" _           
" _ __   ___  _____   _(_)_ __ ___  
" | '_ \ / _ \/ _ \ \ / / | '_ ` _ \ 
" | | | |  __/ (_) \ V /| | | | | | |
" |_| |_|\___|\___/ \_/ |_|_| |_| |_|

set number
set mouse=a
set encoding=UTF-8
set relativenumber

" KEY MAPS
" -------------------------------------------
" inoremap: maps the key in insert mode
" nnoremap: maps the key in normal mode
" vnoremap: maps the key in visual mode
" <C>: Represents the control key
" <A>: Represents the alt key.
" -------------------------------------------
" Copy and paste with Ctrl+c and Ctrl+v
vnoremap <C-c> "+y
nnoremap <C-v> "+p
" Remaping Esc key
inoremap <C-a> <Esc>
" Saving the file
nnoremap <C-s> :w<CR>
" NerdTree maps -> CR = Carriage Return = Pressing ENTER key
nnoremap <C-f> :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-l> :call CocActionAsync('jumpDefinition')<CR>
" Plugins
call plug#begin()
Plug 'http://github.com/tpope/vim-surround' " Surrounding ysw)
Plug 'https://github.com/vim-airline/vim-airline' "Vim Airline
Plug 'https://github.com/ap/vim-css-color' "css colors
" Plug 'https://github.com/neoclide/coc.nvim'  " Auto Completion
Plug 'https://github.com/ryanoasis/vim-devicons' " Developer Icons
Plug 'https://github.com/preservim/nerdtree' " NerdTree
Plug 'https://github.com/tpope/vim-commentary' "Commentary
Plug 'https://github.com/rafi/awesome-vim-colorschemes' " Retro Scheme
call plug#end()

" Setting icons for NerdTree
let g:NERDTreeDirArrowExpandable="+"
let g:NERDTreeDirArrowCollapsible="~"
