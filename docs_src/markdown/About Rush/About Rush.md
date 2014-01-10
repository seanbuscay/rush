About Rush  {#doc-about-rush}
===============

[TOC]

@brief An introduction to the Drush Rush project, including the project's purpose, background, and example usage.

About Rush  {#page-about-rush}
====================

*Drush tools to enhance and improve Drupal development operations and workflow.*

Rush is a tool to run parameterized builds with Drush.

Rush is like [Apache Ant](http://ant.apache.org/) for Drupal.

Rush uses parameters and processes described in build files to build Drupal project instances.

## Purpose {#sec-purpose}

The project's purpose is to allow Drupal Developers to:

- Reduce typical Drupal development workflows down to one step (one Drush command).
- Create re-usable and share-able Drupal development operations and workflows.

## Background {#sec-background}

This project originates out of experience using [Jenkins](http://jenkins-ci.org/) to automate building and testing Drupal projects.

Rush was created to be a light and focused tool to automate repetitive workflows specifically for Drupal developers.

Rush is easier to setup and share jobs than it is to setup Jenkins and share its jobs.

For those developers already using Drush, Rush should not be a significant change to any current workflows.

In most cases the build jobs are a series of core drush commands chained together to complete a full build process with a single command.

## A Few Points about Drush Rush Jobs {#sec-about-jobs}

1.  Drush Rush jobs are **written once then used repeatedly**. *There is probably little value to writing a Drush Rush job for a one time build process.*
2.  Drush Rush jobs are **extendable**.  Complex jobs may be written by extending and or combining similar jobs.
3.  Drush Rush jobs are **shareable** so a job written by one developer may be shared with many.
4.  Drush Rush jobs are **light weight**.  Drush Rush may be used to execute steps as part of a continuous integration or automated testing process, however, it is not a CI or Testing Suite.

## An Illustrated Use Case {#sec-use-case}

[Download an Illustrated Use Case PDF](Drush-Rush-Use-Case-Illustration.pdf)

## Example Usage {#sec-example}

Run a Drush Rush command like:

    drush rush myjob.init

To parse the job folder's rush files for build parameters and build operations and then execute the following operations:

1. Make the build directory
2. Put the directory in the web root
3. Add other directories and files to the build (setup the build skeleton)
4. Create a docroot folder for the Drupal code base
5. Build the code base with Drush Make using specified makefile(s) and prepare the site for install
6. Create the specified database
7. Create the specified dns and virtual host entries
8. Run any pre-build commands
9. Run any pre-build scripts
10. Create build aliases.drushrc.php files
11. Install the site
12. Change variable values as specified
13. Run any post-build commands
14. Run any post-build scripts
15. Put the build under version control
16. Create a remote repo (such as on GITHUB), commit the code, and push it
