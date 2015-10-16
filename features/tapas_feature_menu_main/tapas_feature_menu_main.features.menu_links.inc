<?php
/**
 * @file
 * tapas_feature_menu_main.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function tapas_feature_menu_main_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-primary-menu_about:node/228
  $menu_links['menu-primary-menu_about:node/228'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/228',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn more about the TAPAS project',
      ),
      'identifier' => 'menu-primary-menu_about:node/228',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_activity:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_activity:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'Activity',
    'options' => array(
      'attributes' => array(
        'title' => 'View recent activity of TAPAS community (including new items, collections, projects; forum discussions; new members;)',
      ),
      'identifier' => 'menu-primary-menu_activity:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_advanced-search:search
  $menu_links['menu-primary-menu_advanced-search:search'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Advanced Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_advanced-search:search',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_discover:node/3',
  );
  // Exported menu link: menu-primary-menu_all-institutions:list-all-institutions
  $menu_links['menu-primary-menu_all-institutions:list-all-institutions'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'list-all-institutions',
    'router_path' => 'list-all-institutions',
    'link_title' => 'All Institutions',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_all-institutions:list-all-institutions',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_more:<front>',
  );
  // Exported menu link: menu-primary-menu_community:node/2
  $menu_links['menu-primary-menu_community:node/2'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Community',
    'options' => array(
      'attributes' => array(
        'title' => 'View and engage the TAPAS user community',
      ),
      'identifier' => 'menu-primary-menu_community:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_data-commons:http://tapasdev.neu.edu/?q=discover
  $menu_links['menu-primary-menu_data-commons:http://tapasdev.neu.edu/?q=discover'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=discover',
    'router_path' => '',
    'link_title' => 'DATA Commons',
    'options' => array(
      'attributes' => array(
        'title' => 'View data information and stats on the content housed in the TAPAS central respository',
      ),
      'identifier' => 'menu-primary-menu_data-commons:http://tapasdev.neu.edu/?q=discover',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_discover:node/3',
  );
  // Exported menu link: menu-primary-menu_discover:node/3
  $menu_links['menu-primary-menu_discover:node/3'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Discover',
    'options' => array(
      'attributes' => array(
        'title' => 'Discover projects, collections, items in the TAPAS archive',
      ),
      'identifier' => 'menu-primary-menu_discover:node/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_explore-tapas:http://tapasdev.neu.edu/?q=node/230
  $menu_links['menu-primary-menu_explore-tapas:http://tapasdev.neu.edu/?q=node/230'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/230',
    'router_path' => '',
    'link_title' => 'Explore TAPAS',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn More About Project Development and Publishing Features in TAPAS',
      ),
      'identifier' => 'menu-primary-menu_explore-tapas:http://tapasdev.neu.edu/?q=node/230',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_about:node/228',
  );
  // Exported menu link: menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/
  $menu_links['menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/234/',
    'router_path' => '',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_faq:http://tapasdev.neu.edu/?q=node/234/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/',
  );
  // Exported menu link: menu-primary-menu_featured-content:http://tapasdev.neu.edu/?q=discover
  $menu_links['menu-primary-menu_featured-content:http://tapasdev.neu.edu/?q=discover'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=discover',
    'router_path' => '',
    'link_title' => 'Featured Content',
    'options' => array(
      'attributes' => array(
        'title' => 'View featured TAPAS projects, collections, items, and members',
      ),
      'identifier' => 'menu-primary-menu_featured-content:http://tapasdev.neu.edu/?q=discover',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_discover:node/3',
  );
  // Exported menu link: menu-primary-menu_history-of-tapas:http://tapasdev.neu.edu/?q=node/228
  $menu_links['menu-primary-menu_history-of-tapas:http://tapasdev.neu.edu/?q=node/228'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/228',
    'router_path' => '',
    'link_title' => 'History of TAPAS',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn the story and about the people behind the TAPAS project',
      ),
      'identifier' => 'menu-primary-menu_history-of-tapas:http://tapasdev.neu.edu/?q=node/228',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_about:node/228',
  );
  // Exported menu link: menu-primary-menu_memberships:http://tapasdev.neu.edu/?q=node/228
  $menu_links['menu-primary-menu_memberships:http://tapasdev.neu.edu/?q=node/228'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/228',
    'router_path' => '',
    'link_title' => 'Memberships',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn more about free and upgraded TAPAS accounts',
      ),
      'identifier' => 'menu-primary-menu_memberships:http://tapasdev.neu.edu/?q=node/228',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_about:node/228',
  );
  // Exported menu link: menu-primary-menu_more:<front>
  $menu_links['menu-primary-menu_more:<front>'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'More',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_more:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_my-tapas:my_tapas
  $menu_links['menu-primary-menu_my-tapas:my_tapas'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'my_tapas',
    'router_path' => 'my_tapas',
    'link_title' => 'My Tapas',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_my-tapas:my_tapas',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_news:news
  $menu_links['menu-primary-menu_news:news'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_news:news',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_people-:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_people-:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'People ',
    'options' => array(
      'attributes' => array(
        'title' => 'View directory of TAPAS user community',
      ),
      'identifier' => 'menu-primary-menu_people-:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_site-support-forums:http://tapasdev.neu.edu/?q=node/234/
  $menu_links['menu-primary-menu_site-support-forums:http://tapasdev.neu.edu/?q=node/234/'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/234/',
    'router_path' => '',
    'link_title' => 'Site Support Forums',
    'options' => array(
      'attributes' => array(
        'title' => 'Access site support forums',
      ),
      'identifier' => 'menu-primary-menu_site-support-forums:http://tapasdev.neu.edu/?q=node/234/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/',
  );
  // Exported menu link: menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/
  $menu_links['menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/234/',
    'router_path' => '',
    'link_title' => 'Support',
    'options' => array(
      'attributes' => array(
        'title' => 'Access Site and TEI Support Services',
      ),
      'identifier' => 'menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-primary-menu_tapas--dev:http://tapasdev.neu.edu/?q=node/228
  $menu_links['menu-primary-menu_tapas--dev:http://tapasdev.neu.edu/?q=node/228'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/228',
    'router_path' => '',
    'link_title' => 'TAPAS | Dev',
    'options' => array(
      'attributes' => array(
        'title' => 'Learn more about the TAPAS development team and their current and future development work',
      ),
      'identifier' => 'menu-primary-menu_tapas--dev:http://tapasdev.neu.edu/?q=node/228',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_about:node/228',
  );
  // Exported menu link: menu-primary-menu_tapas--learn:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_tapas--learn:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'TAPAS | Learn',
    'options' => array(
      'attributes' => array(
        'title' => 'Information and sign-ups for workshops, code-alongs, and clinics',
      ),
      'identifier' => 'menu-primary-menu_tapas--learn:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_tei-forums:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_tei-forums:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'TEI Forums',
    'options' => array(
      'attributes' => array(
        'title' => 'Conversations about TEI',
      ),
      'identifier' => 'menu-primary-menu_tei-forums:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_tei-guidelines:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_tei-guidelines:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'TEI Guidelines',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-primary-menu_tei-guidelines:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_tei-help:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_tei-help:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'TEI Help',
    'options' => array(
      'attributes' => array(
        'title' => 'Access TEI support services and resources',
      ),
      'identifier' => 'menu-primary-menu_tei-help:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/',
  );
  // Exported menu link: menu-primary-menu_tei-resources-and-support:http://tapasdev.neu.edu/?q=commons
  $menu_links['menu-primary-menu_tei-resources-and-support:http://tapasdev.neu.edu/?q=commons'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=commons',
    'router_path' => '',
    'link_title' => 'TEI Resources and Support',
    'options' => array(
      'attributes' => array(
        'title' => 'Access TEI markup and project support services and documentation ',
      ),
      'identifier' => 'menu-primary-menu_tei-resources-and-support:http://tapasdev.neu.edu/?q=commons',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_community:node/2',
  );
  // Exported menu link: menu-primary-menu_tickets:http://tapasdev.neu.edu/?q=node/234/
  $menu_links['menu-primary-menu_tickets:http://tapasdev.neu.edu/?q=node/234/'] = array(
    'menu_name' => 'menu-primary-menu',
    'link_path' => 'http://tapasdev.neu.edu/?q=node/234/',
    'router_path' => '',
    'link_title' => 'Tickets',
    'options' => array(
      'attributes' => array(
        'title' => 'View and submit support tickets',
      ),
      'identifier' => 'menu-primary-menu_tickets:http://tapasdev.neu.edu/?q=node/234/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-primary-menu_support:http://tapasdev.neu.edu/?q=node/234/',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Activity');
  t('Advanced Search');
  t('All Institutions');
  t('Community');
  t('DATA Commons');
  t('Discover');
  t('Explore TAPAS');
  t('FAQ');
  t('Featured Content');
  t('History of TAPAS');
  t('Memberships');
  t('More');
  t('My Tapas');
  t('News');
  t('People ');
  t('Site Support Forums');
  t('Support');
  t('TAPAS | Dev');
  t('TAPAS | Learn');
  t('TEI Forums');
  t('TEI Guidelines');
  t('TEI Help');
  t('TEI Resources and Support');
  t('Tickets');

  return $menu_links;
}
