--Configuration of the lsp
return {
	{
		--Mason installation
		"williamboman/mason.nvim",
		config = function()
			require("mason").setup()
		end,
	},
	dependencies = {
		"WhoIsSethDaniel/mason-tool-installer.nvim",
	},
	{
		--Configuring default packages
		"williamboman/mason-lspconfig.nvim",
		config = function()
			require("mason-lspconfig").setup({
				ensure_installed = {
					"lua_ls",
					"pyright",
					"clangd",
					"bashls",
				},
			})
		end,
	},
	{
		--Setting up linters
		"neovim/nvim-lspconfig",
		config = function()
			local lspconfig = require("lspconfig")
			lspconfig.pyright.setup({}) --for python
			lspconfig.lua_ls.setup({}) --for lua
			lspconfig.ruff_lsp.setup({ --for python too (optional)
				init_options = {
					settings = {
						-- Any extra CLI arguments for `ruff` go here.
						args = {},
					},
				},
			})
			lspconfig.clangd.setup({}) --For C/C++
			lspconfig.bashls.setup({
				cmd = { "bash-language-server", "start" },
				filetypes = { "sh", "zsh", "bash" },
			}) --For bash scripting
		end,
	},
}
