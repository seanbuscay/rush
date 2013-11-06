Environment Based Global Pre and Post Operations {#doc-environment-based-global-pre-post}
===============

[TOC]

@brief Notes about Environment Based Global Pre and Post Operations

Environment Based Global Pre and Post Operations {#page-environment-based-global-pre-post}
====================

Suppose you want to automatically install the Drupal Coder module on every Drush Rush built site. Simply add a new file called `post.rush.ini` to your `environment` folder. Then add rush commands to it like any other rush file.  In this case add:

    [c] = 'drush dl coder; drush en -y coder' 

From now on, **every** rush job that runs on your local system will have a last command in it to download and enable the coder module.