# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Tails and Trails'
copyright = '2024, Ethan Oliveira, Sol Kwak'
author = 'Ethan Oliveira, Sol Kwak'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = []

templates_path = ['_templates']
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output
# Theme configuration
html_theme = "furo"

# Custom options for Furo
html_theme_options = {
    "dark_css_variables": {           # Set dark mode colors
        "color-background-primary": "#131416",
        "color-background-secondary": "#1a1c1e",
        "color-foreground-primary": "#ffffff",
        "color-foreground-secondary": "#d0d0d0",
        "color-brand-primary": "#ff6600",  # Accent color (optional)
    },
}

# Add custom static path if needed
html_static_path = ['_static']
html_css_files = [
    'css/custom.css',  # Link to your custom CSS
]