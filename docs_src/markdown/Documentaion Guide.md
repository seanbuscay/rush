Welcome to the Drush Rush Project Documentation Guide  {#mainpage}
=====================================================

@brief  A guide to help you find what you need to use Drush Rush.

Documentation Guide  {#doc-documentation-guide}
===================

[TOC]

This guide is meant to help you find what you need to use Drush Rush to:

  - Reduce typical Drupal development work flows down to one step (one Drush command).
  - Create re-usable and share-able Drupal development operations and work flows.

## Drush Rush README  {#sec-readme}

The [Rush Project README file](@ref readme-file) provides an introduction to the Drush
Rush project, including the project's purpose, background, and example usage.

## For End Users  {#sec-end-users}

### Install Guide {#sec-install-guide}

The @ref doc-install-guide covers how to install the Drush Rush module and how to setup your Rush Application folder.

### Key Concepts {#sec-key-terminology}

Read @ref doc-key-terminology to get a good overview of the terminology and concepts used in Drush Rush.

### End User Documentation {#sec-end-user-documentation}

The @ref doc-end-user covers how to use Drush Rush, how to create Drush Rush jobs and build your projects.

### Job Templates {#sec-job-templates}

There are a number of example jobs in the RushTemplates directory.

You can use them from the RushTemplates directory or copy them into your own jobs directory and customize them.

To see a list of the jobs in the job templates folder run:

    drush rush-list --show=jt

To see a see a description of the job with information on how it works run:

    drush rush <job-name> --show=help

For example, to see how tests.filesystem works run:

    drush rush tests.filesystem --show=help

## For Developers {#sec-developers}

### Developer Guide {#sec-developer-guide}

The [Developer Guide](@ref doc-developer-guide) provides an introduction to the coding conventions in the project.

### Lists: Todo, Backlog, and Bugs {#sec-lists}

The following lists are generated from inline code comments.

- @ref todo
- @ref backlog
- @ref bug

### Tips for Navigating Code Documentation {#sec-code-doc-nav}

#### Main Navigation {#sec-main-nav}

Note the main navigation bar at the top of this page.

- The [Related Pages link](pages.html) takes you to a page which lists all the documentation files in the project.

- The [Files link](files.html) takes you to a page which provides a directory listing of all code files (mainly php files) in the code base.  Markdown and ini files are not shown in this list.  Just code.
  + Click a filename link to go to the documentation for that file.

- The [Modules page](modules.html) provides a nice way to browse the code documentation around functional groupings.
  + For example, to view all Operations functions, visit @ref operations .
  + To view the File System functions within the Operations functions group visit @ref filesystem-functions .

  > **Note:** Doxygen documentation calls any grouping of code 'modules'.  The term 'modules' in this case does not mean the same thing as 'Drupal modules'.

- The [Main Page link](index.html) will take you back to this page you are on now.

#### Search Bar {#sec-search}

The search bar at the top of the page provides auto complete search functionality to find most any documented item in the Rush project.
